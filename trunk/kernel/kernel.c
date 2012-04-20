#ifndef STRLEN
#  define STRLEN 81
#endif
#define _true 1
#define _false 0
typedef unsigned char boolean;
typedef int integer;
typedef char* string;
#include "kernel.h"
void kernel_I_ev(Event);
int kernel(void);
int kernel_reset(void);
#ifndef _NO_EXTERN_DEFINITIONS
#  ifndef _NO_CONSTANT_DEFINITIONS
#  endif /* _NO_CONSTANT_DEFINITIONS */
#  ifndef _NO_FUNCTION_DEFINITIONS
#    ifndef _do_lookup_DEFINED
#      ifndef do_lookup
extern string do_lookup(Event);
#      endif
#    endif
#  endif /* _NO_FUNCTION_DEFINITIONS */
#  ifndef _NO_PROCEDURE_DEFINITIONS
#  endif /* _NO_PROCEDURE_DEFINITIONS */
#endif /* _NO_EXTERN_DEFINITIONS */

static struct {
  unsigned int ev : 1;
  unsigned int fun : 1;
} _s = {  0,  0 };
#define tick 1
static Event ev_v;
static char fun_v[STRLEN];
static Event X;
static char f[STRLEN];
static unsigned char _state_1 = 1;
void kernel_I_ev(Event _v) {
  _s.ev = 1;
  ev_v = _v;
}

int kernel(void)
{
  /* Vacuous terminate */;
  if (_state_1) {
    _s.fun = 0, strcpy(fun_v, "None");;;
    _state_1 = 0;
  } else {
    _state_1 = 0;
    if (_s.ev) {
      _Event(&X, ev_v);
      strcpy(f, do_lookup(X));
      (strcpy(fun_v, f)), (_s.fun = 1);
    }
  }
  if (_s.fun) { kernel_O_fun(fun_v); _s.fun = 0; }
  _s.ev = 0;
  return 1;
}

int kernel_reset(void)
{
  _s.ev = 0;
  return 0;
}
