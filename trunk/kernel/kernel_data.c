
#include<stdio.h>
#include <string.h>
#include "kernel.h"


	
/*
	transfer inputs from the driver code to the reactive kernel
*/
int kernel_O_fun(char * s)
{
/*TODO: Send the function call string to a python program*/
	printf("%s\n",s);
}
Event get_input(){
	// get event from stdin and parse the data
	char s[80], *tok,*st,*saveptr;
	int i,j;
	Event ev;
	ev.type=-1;
	if(fgets(s,80,stdin)==NULL)
		return ev;

/*
*	format of the input is
*	set cur x 0.309375 0.42916667 0.0 0.0 0.0
*/

	
	st=s;
	#define delim " "
	tok=strtok_r(st,delim,&saveptr );
	if(strcmp(tok,"set")==0) 
	//the token is "set"
	{
		st=NULL;
	// eat cur and x
		tok=strtok_r(st,delim,&saveptr );
		tok=strtok_r(st,delim,&saveptr );
		ev.type=0;
		ev.x=atof(strtok_r(st,delim,&saveptr ));
		ev.y=atof(strtok_r(st,delim,&saveptr ));
		#undef delim
		return ev;
	}
	// the token is not "set"
	#ifdef DEBUG
	printf("..\n",tok);
	#endif
	return get_input();

}
int main()
{
	Event ev;
	//infinite loop
	while(1){
		//get the input from the user
		ev = get_input();
		if (ev.type==-1)
			return 0;
		//did we get an event??
		#ifdef DEBUG
		printf("::::::>Got an event with x=%f, y=%f\n", ev.x, ev.y);
		#endif
		// input the event to the kernel
		kernel_I_ev(ev);
		//call the kernel 
		kernel();
		kernel_reset();

	}
	
}
