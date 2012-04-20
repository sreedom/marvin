#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//Event type definition: needed by kernel.c

// Event Types
typedef enum event_types { BLOB, TAP, PRESS,
		LINE, ZOOM,
		NONE = 0xff 
} t_event;

//Single finger Spatial
struct Blob{
	//t_event type;
	//Values
	double x,y;
};
//Single finger Temporal
struct Tap{
	//t_event type;
	//Values
	double x,y;
	int n;
};
struct Press{
	//t_event type;
	//Values
	double x,y;
	int t;
};

//Two finger Spatial
struct Line{
	//t_event type;
	//Values
	double x1,y1, x2,y2;
};
struct Zoom{
	//t_event type;
	//Values
	struct Line l1,l2;
};
	 

typedef union {
	//Spatial
	struct Blob blob;
	struct Line line;
	//TODO Add more spatial gestures
	
	//Temporal
	struct Tap tap;
	struct Press press;
	struct Zoom zoom;
	
} _event;

typedef struct{
	_event ev;
	t_event type;
} Event;

//EVENT Assignment function (full copy)
#define _Event(x,y) (*(x)=y)


char * do_lookup(Event);


// Definitions needed for other files

//Lookup table Entry
typedef struct {
	t_event type;
	char  funName[100];
} lookupEntry;

typedef struct {
	lookupentry l;
	Event ev;
}r_event;


