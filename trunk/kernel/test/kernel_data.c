
#include<stdio.h>
#include <string.h>
#include "kernel.h"
#include "pyBindings.h"

/*
Kernel output function
*/	
int kernel_O_fun(char * s)
{
/*TODO: Call the python function with the arguments */
	call_python_function(s);
	//printf("%s\n",s);
}

/*
	transfer inputs from the driver code to the reactive kernel
*/



Event get_input(){
	// get event from stdin and parse the data
	char s[80], *tok,*st,*saveptr;
	int i,j;
	Event ev;
	//default Event type = NONE
	ev.type=0xff;
	if(fgets(s,80,stdin)==NULL)
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
	
	// the token is not "Blob" or "Line"
	#ifdef DEBUG
	printf("..\n",tok);
	#endif
	return get_input();

}


/*  A lookup table (of sorts)
    For Testing only. This needs to be modified, with provisions to Parse an input file, and create output files
    TODO Grosly Ugly code. Change. compile with dummy.c
*/

lookupEntry lookupTable[10];

/* dummy lookup function */
// has to be char * as per Esterel specification
char * stringify(r_event ret)
{
	char *funCall=(char *) malloc(50), *arg=(char *) malloc(50);
	int i;
	switch(ret.l.type)
	{
		case BLOB:
			sprintf(arg,"'%f,%f'",ret.ev.ev.blob.x,ret.ev.ev.blob.y);
			break;
		case LINE:
			sprintf(arg,"'%f,%f,%f,%f'", ret.ev.ev.line.x1, ret.ev.ev.line.y1, ret.ev.ev.line.x2, ret.ev.ev.line.y2);
			break;
		default:
			sprintf(arg,"None");
	}
	i=sprintf(funCall,"%s(%s)", ret.l.funName,arg);
	#ifdef DEBUG
	printf("::::::>Calling python function %s\n", funCall);
	#endif
	return funCall;

}
char * do_lookup(Event ev)
{
	int i;
	r_event ret;
	#ifdef DEBUG
	printf("::::::>doing lookup on an event with type %d\n", ev.type);
	#endif
	for(i=0;lookupTable[i].type != NONE;i++)
	{
		if (ev.type==lookupTable[i].type)
		{
			ret.l= lookupTable[i];
			ret.ev=ev;
			return stringify(ret);
		}
	}
	return lookupTable[i].funName;
	
}



int main(int argc, char ** argv)
{
	int x;
	Event ev;
	FILE* fp;
	// create dummy lookupTable
	get_dummy_lookup(lookupTable);
	
	//initialize python
	Py_Initialize();
	if ( x= Py_IsInitialized()){
		printf(" Something went wrong in inititalization %d\n",x);
	}
	PySys_SetArgv(argc,argv);
	//initialize threads as well
	PyEval_InitThreads();
	//initialize the program
	fp=fopen("example/e1.py","r");
	printf("Running the inittialization code\n");
	if( x= PyRun_AnyFile(fp,"example/e1.py"))
		printf("something went wrong in running the code %d\n",x);

	//infinite loop	
	//TODO: write functions to catch interrupts
	
	while(1){
		//get the input from the user
		#ifdef DEBUG
		printf("::::::>Getting input from stdin\n");
		printf("d_input: ");
		#endif
		ev = get_input();
		//did we get an event??
		#ifdef DEBUG
		printf("::::::>Got an event with type %d\n", ev.type);
		#endif
		if (ev.type==NONE)
		{
			kernel_reset();
			Py_Finalize();
			return 0;
		}
		// input the event to the kernel
		#ifdef DEBUG
		printf("::::::>Passing event with type %d to the kernel\n", ev.type);
		#endif
		kernel_I_ev(ev);
		//call the kernel 
		kernel();
		
		//kernel_reset();

	}
}
	

