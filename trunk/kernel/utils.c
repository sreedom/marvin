
#include "kernel.h"
void _Event(Event * ev, Event data){
	*(ev) = data;
}
char * do_lookup(Event ev)
{
	char * s = malloc(80);
	sprintf(s,"print \"%f %f\"",ev.x, ev.y);
	return s;
}
