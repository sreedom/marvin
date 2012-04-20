#include <stdio.h>
#include "tuioDriver.h"

Event get_input( char * s){
	// parse the data from s and return corresponding event
	char  *tok,*st,*saveptr;
	int i,j;
	Event ev;
	//default Event type = NONE
	ev.type=0xff;
	if(s==NULL)
		return ev;

/*
*	format of the input is
*	Blob 20 at 0.484023 0.277425
*	Line 19 18 at 0.662348 0.337381 0.190000 0.505056
*/

	
	st=s;
	#define delim " "
	tok=strtok_r(st,delim,&saveptr );
	if(strcmp(tok,"Blob")==0) 
	//the token is "Blob"
	{
		st=NULL;
	// eat 20 and at
		tok=strtok_r(st,delim,&saveptr );
		tok=strtok_r(st,delim,&saveptr );
		ev.type=BLOB;
		ev.ev.blob.x=atof(strtok_r(st,delim,&saveptr ));
		ev.ev.blob.y=atof(strtok_r(st,delim,&saveptr ));
		return ev;
	}
	
	else if(strcmp(tok,"Line")==0)
	//the token is "Line"
	{
		st=NULL;
	// eat 19, 18 and at
		tok=strtok_r(st,delim,&saveptr );
		tok=strtok_r(st,delim,&saveptr );
		tok=strtok_r(st,delim,&saveptr );
				
		ev.type=LINE;
		ev.ev.line.x1=atof(strtok_r(st,delim,&saveptr ));
		ev.ev.line.y1=atof(strtok_r(st,delim,&saveptr ));
		ev.ev.line.x2=atof(strtok_r(st,delim,&saveptr ));
		ev.ev.line.y2=atof(strtok_r(st,delim,&saveptr ));
		return ev;
	}
	#undef delim
	else{
		// the token is not "Blob" or "Line"
		#ifdef DEBUG
		printf("..**..\n",tok);
		#endif
		return ev;
	}

}



Event  get_event()
{
    PyObject *pName, *pModule, *pDict, *pFunc;
    PyObject *pArgs, *pValue;
    int i;
    Event ev;
    
    Py_Initialize();
    pName = PyString_FromString(MODULENAME);
    /* Error checking of pName left out */

    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule, FUNC);
        /* pFunc is a new reference */

        if (pFunc && PyCallable_Check(pFunc)) {
            pArgs = PyTuple_New(0);
            pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
            if (pValue != NULL) {
                printf("Result of call: %ld\n", PyString_AsString(pValue));
                Py_DECREF(pValue);
                ev= get_input(PyString_AsString(pValue));
                return ev;
 //TODO code completion
           }
            else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr,"Call failed\n");
                return ev;
            }
        }
        else {
            if (PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function \"%s\"\n", FUNC);
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else {
        PyErr_Print();
        fprintf(stderr, "Failed to load \"%s\"\n", MODULENAME);
        return ev;
    }

 }
