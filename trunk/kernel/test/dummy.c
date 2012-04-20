
//This better go away... Soon

#include "kernel.h"
#include <string.h>

lookupEntry new(t_event type, char * data)
{
	lookupEntry l;
	l.type=type;
	strcpy(l.funName,data);
	return l;
}
//format:
//T[0] = new ( BLOB , "doit")

void get_dummy_lookup(lookupEntry T[])
{
	T[0] = new( BLOB , "do_blob" );
	T[1] = new( LINE , "do_line" );
	T[2] = new( TAP  , "pass"  );
	T[3] = new( ZOOM , "pass" );
	T[4] = new( NONE , "sys.exit(0)");
}

	
	
