/* sscc : C CODE OF SORTED EQUATIONS kernel - INLINE MODE */

/* AUXILIARY DECLARATIONS */

#ifndef STRLEN
#define STRLEN 81
#endif
#define _COND(A,B,C) ((A)?(B):(C))
#ifdef TRACE_ACTION
#include <stdio.h>
#endif
#ifndef NULL
#define NULL ((char*)0)
#endif

#ifndef __EXEC_STATUS_H_LOADED
#define __EXEC_STATUS_H_LOADED

typedef struct {
unsigned int start:1;
unsigned int kill:1;
unsigned int active:1;
unsigned int suspended:1;
unsigned int prev_active:1;
unsigned int prev_suspended:1;
unsigned int exec_index;
unsigned int task_exec_index;
void (*pStart)();
void (*pRet)();
} __ExecStatus;

#endif
#define __ResetExecStatus(status) {\
   status.prev_active = status.active; \
   status.prev_suspended = status.suspended; \
   status.start = status.kill = status.active = status.suspended = 0; }
#define __DSZ(V) (--(V)<=0)
#define BASIC_TYPES_DEFINED
typedef int boolean;
typedef int integer;
typedef char* string;
#define _true 1
#define _false 0
#define __kernel_GENERIC_TEST(TEST) return TEST;
typedef void (*__kernel_APF)();
static __kernel_APF *__kernel_PActionArray;

#include "kernel.h"

/* EXTERN DECLARATIONS */

#ifndef _NO_EXTERN_DEFINITIONS
#ifndef _NO_FUNCTION_DEFINITIONS
#ifndef _do_lookup_DEFINED
#ifndef do_lookup
extern string do_lookup(Event);
#endif
#endif
#endif
#ifndef _NO_PROCEDURE_DEFINITIONS
#ifndef __Event_DEFINED
#ifndef _Event
extern void _Event(Event* ,Event);
#endif
#endif
#endif
#endif

/* INITIALIZED CONSTANTS */

/* MEMORY ALLOCATION */

static Event __kernel_V0;
static boolean __kernel_V1;
static char __kernel_V2[STRLEN];
static Event __kernel_V3;
static char __kernel_V4[STRLEN];


/* INPUT FUNCTIONS */

void kernel_I_ev (Event __V) {
_Event(&__kernel_V0,__V);
__kernel_V1 = _true;
}

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

#define __kernel_A1 \
__kernel_V1

/* OUTPUT ACTIONS */

#define __kernel_A2 \
kernel_O_fun(__kernel_V2)

/* ASSIGNMENTS */

#define __kernel_A3 \
__kernel_V1 = _false
#define __kernel_A4 \
strcpy(__kernel_V2,"None")
#define __kernel_A5 \
_Event(&__kernel_V3,__kernel_V0)
#define __kernel_A6 \
strcpy(__kernel_V4,do_lookup(__kernel_V3))
#define __kernel_A7 \
strcpy(__kernel_V2,__kernel_V4)
#define __kernel_A8 \
strcpy(__kernel_V2,"NOTHING")

/* PROCEDURE CALLS */

/* CONDITIONS */

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

#define __kernel_A9 \

#define __kernel_A10 \

#define __kernel_A11 \


/* ACTION SEQUENCES */

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int kernel_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */



static void __kernel__reset_input () {
__kernel_V1 = _false;
}

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __kernel_R[2] = {_true,
 _false};

/* AUTOMATON ENGINE */

int kernel () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[5];
E[0] = __kernel_R[1]&&!(__kernel_R[0]);
E[1] = E[0]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__kernel_A1);
if (E[1]) {
__kernel_A5;
#ifdef TRACE_ACTION
fprintf(stderr, "__kernel_A5\n");
#endif
}
if (E[1]) {
__kernel_A6;
#ifdef TRACE_ACTION
fprintf(stderr, "__kernel_A6\n");
#endif
}
if (E[1]) {
__kernel_A7;
#ifdef TRACE_ACTION
fprintf(stderr, "__kernel_A7\n");
#endif
}
E[0] = E[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__kernel_A1));
if (E[0]) {
__kernel_A8;
#ifdef TRACE_ACTION
fprintf(stderr, "__kernel_A8\n");
#endif
}
if (E[1]||E[0]) {
__kernel_A2;
#ifdef TRACE_ACTION
fprintf(stderr, "__kernel_A2\n");
#endif
}
E[2] = __kernel_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__kernel_A1));
if (E[2]) {
__kernel_A9;
#ifdef TRACE_ACTION
fprintf(stderr, "__kernel_A9\n");
#endif
}
if (__kernel_R[0]) {
__kernel_A4;
#ifdef TRACE_ACTION
fprintf(stderr, "__kernel_A4\n");
#endif
}
E[3] = !(_true);
if (__kernel_R[0]) {
__kernel_A10;
#ifdef TRACE_ACTION
fprintf(stderr, "__kernel_A10\n");
#endif
}
if (__kernel_R[0]) {
__kernel_A11;
#ifdef TRACE_ACTION
fprintf(stderr, "__kernel_A11\n");
#endif
}
__kernel_R[1] = __kernel_R[0]||E[1]||E[0];
E[4] = __kernel_R[1];
__kernel_R[0] = !(_true);
__kernel__reset_input();
return E[4];
}

/* AUTOMATON RESET */

int kernel_reset () {
__kernel_R[0] = _true;
__kernel_R[1] = _false;
__kernel__reset_input();
return 0;
}
