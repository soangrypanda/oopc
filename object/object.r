#ifndef OOPC_OBJECT_R_SENTRY
#define OOPC_OBJECT_R_SENTRY

#include <stddef.h>
#include <stdarg.h>


void *object_ctor(void *const _self, va_list *app);
void *object_dtor(void *const _self);
void print_o(const void *const _self);
void *copy_o(const void *const _self);
int  object_compare(const void *const _self, const void *const _other);


#define OBJECT_VT        size_t size;                                              \
                         void *(*const ctor)(void *const _self, va_list *app);     \
                         void *(*const dtor)(void *const _self);                   \
                         void  (*const print)(const void *const _self);            \
                         void *(*const copy)(const void *const _self);             \
                         int   (*compare)(const void *const _self, const void *const _other); \
                         int   (*const a_getter)(const void *const _self);

#define OBJECT_VT_INIT  .size     = sizeof(struct object_class_s),  \
                        .ctor     = object_ctor,                    \
                        .dtor     = object_dtor,                    \
                        .print    = object_print,                   \
                        .copy     = object_copy,                    \
                        .compare  = object_compare,                 \
                        .a_getter = object_a_getter

struct object_vt_s {
    OBJECT_VT;
};

struct object_class_s {
    struct object_vt_s *const vt;
    int a;
    int b;
};


#endif
