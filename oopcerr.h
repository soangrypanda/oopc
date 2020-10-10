#ifndef OOPC_STDOOPC_H_SENTRY
#define OOPC_STDOOPC_H_SENTRY

#include <stdio.h>
#include <stdlib.h>

#define EWRONGOBJ -1
#define EWRONGOBJ_TXT "pointer to invalid object passed"

//void exit_error(char *errtxt, const int error_code);


#define exit_error(errtxt, err_code)                                  \
        char *txt = __FILE__ ": " errtxt ": " err_code ## _TXT ".\n"; \
        if((err_code) < 0) {                                          \
             fputs(txt, stderr); \
        }                                                                      \
        exit(1)  


#endif
