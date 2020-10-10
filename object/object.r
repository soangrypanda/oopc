#ifndef OOPC_OBJECT_R_SENTRY
#define OOPC_OBJECT_R_SENTRY

#include <stddef.h>
#include <stdarg.h>

#define OBJECT_VT   size_t size;                                        \
                    void *(*ctor)(void *const _self, va_list *app);     \
                    void *(*dtor)(void *const _self);                   \
                    int (*a_getter)(const void *const _self);

struct object_vt_s {
    OBJECT_VT;
};

struct object_class_s {
    struct object_vt_s *const vt;
    int a;
    int b;
};

#endif
