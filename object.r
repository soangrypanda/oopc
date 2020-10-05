#ifndef OOPC_OBJECT_R_SENTRY
#define OOPC_OBJECT_R_SENTRY

#include <stdarg.h>
#include <stdio.h>
#include <stddef.h> 

struct class {
    size_t size;
    void * (*ctor)(const void *self, va_list *app);
    void * (*dtor)(void *self);
    int (*print)(const void *self);
    int (*add)(const void *self, const void *other);
};

#endif
