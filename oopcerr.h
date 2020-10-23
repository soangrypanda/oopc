#ifndef OOPC_STDOOPC_H_SENTRY
#define OOPC_STDOOPC_H_SENTRY

#include <stdio.h>
#include <stdlib.h>

#define CHECK_IF_OBJ(self) !self || !self->vt || \
                           self->safecheck != passed
#define EWRONGOBJ -1
#define EWRONGOBJ_TXT "pointer to invalid object passed"

#define EDIFFOBJ  -2
#define EDIFFOBJ_TXT  "trying to compare objects of different types"

#define ENOTANOBJ -3
#define ENOTANOBJ_TXT "operand is not an object of any class"

#define ERR_NO     0
#define ERR_NO_TXT    ""


#define exit_error(errtxt, err_code)                                             \
    do                                                                           \
    {                                                                            \
        if((err_code) < 0) {                                                     \
             char *txt = __FILE__ ":" "%d: " errtxt ": " err_code ## _TXT ".\n"; \
             fprintf(stderr,txt, __LINE__);                                      \
        }                                                                        \
        else {                                                                   \
             perror(errtxt);                                                     \
        }                                                                        \
        fflush(0);                                                               \
        exit(1);                                                                 \
    } while(0)

#endif
