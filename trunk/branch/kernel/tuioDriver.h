#include <Python.h>
#include "kernel.h"
#define MODULENAME "pyTUIO"
//TODO copy usingPyTuio3.py as pyTUIO.py in this dir
#define FUNC "get_event"


Event  get_event();
Event get_input( char * s);
