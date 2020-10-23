#ifndef OOPC_OBJECT_R_SENTRY
#define OOPC_OBJECT_R_SENTRY

#include <stddef.h>
#include <stdarg.h>



void *object_ctor(void *const _self, va_list *app);
void *object_dtor(void *const _self);
void object_print(const void *const _self);
void *object_copy(const void *const _self);
int  object_compare(const void *const _self, const void *const _other);
void *object_add(const void *const _self, const void *const _other);
void *object_sub(const void *const _self, const void *const _other);
void *object_mult(const void *const _self, const void *const _other);
void *object_div(const void *const _self, const void *const _other);


struct class_check_s {
    char blank;
};
struct class_check_s class_check = { 0 };
struct class_check_s *passed = &class_check;

#define OBJECT_VT        struct class_check_s *safecheck;                          \
                         void *(*const ctor)(void *const _self, va_list *app);     \
                         void *(*const dtor)(void *_self);                         \
                         void  (*const print)(const void *const _self);            \
                         void *(*const copy)(const void *const _self);             \
                         int   (*compare)(const void *const _self, const void *const _other); \
                         void *(*add)(const void *const _self, const void *const _other);     \
                         void *(*sub)(const void *const _self, const void *const _other);     \
                         void *(*mult)(const void *const _self, const void *const _other);    \
                         void *(*div)(const void *const _self, const void *const _other);     \
                         size_t size

#define OBJECT_VT_INIT  .safecheck= &class_check,                   \
                        .ctor     = object_ctor,                    \
                        .dtor     = object_dtor,                    \
                        .print    = object_print,                   \
                        .copy     = object_copy,                    \
                        .compare  = object_compare,                 \
                        .add      = object_add,                     \
                        .sub      = object_sub,                     \
                        .mult     = object_mult,                    \
                        .div      = object_div,                     \
                        .size     = sizeof(struct object_class_s)


struct object_vt_s {
    OBJECT_VT;
};

struct object_class_s {
    struct object_vt_s *const vt;
    struct class_check_s *safecheck; 
};


#endif
