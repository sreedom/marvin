
#include "kernel.h"
#include <string.h>

lookupEntry new(t_event type, char * data)
{
	lookupEntry l;
	l.type=type;
	strcpy(l.funName,data);
	return l;
}

void get_dummy_lookup(lookupEntry T[])
{
	T[0] = new( BLOB , "doit('0.5,0.5')" );
	T[1] = new( LINE , "doit('0.8,0.7')" );
	T[2] = new( TAP  , "pass"  );
	T[3] = new( ZOOM , "pass" );
	T[4] = new( NONE , "sys.exit(0)");
}

	
	
