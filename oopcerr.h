#ifndef OOPC_STDOOPC_H_SENTRY
#define OOPC_STDOOPC_H_SENTRY

#include <stdio.h>
#include <stdlib.h>

#define EWRONGOBJ -1
#define EWRONGOBJ_TXT "pointer to invalid object passed"

#define ERR_NO     0
#define ERR_NO_TXT    ""


#define exit_error(errtxt, err_code)                                             \
        if((err_code) < 0) {                                                     \
             char *txt = __FILE__ ":" "%d: " errtxt ": " err_code ## _TXT ".\n"; \
             fprintf(stderr,txt, __LINE__);                                      \
        }                                                                        \
        else {                                                                   \
             perror(errtxt);                                                     \
        }                                                                        \
        fflush(0);                                                               \
        exit(1)  

#endif
