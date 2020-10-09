#include "object.h"
#include "object.r"

void *new_o(void *const _self, ...)
{
    struct object_vt_s *const self = _self; 
    if(!self) {
        return 0;
    }
    void *o_ptr = calloc(1, self->size);
    if(errno == ENOMEM) {
        perror("new_o");
        exit(1);
    }
    *(struct object_vt_s**)o_ptr = self; 
    if(!self->ctor) {
        return o_ptr;
    }
    va_list ap;
    va_start(ap, _self);
    self->ctor(o_ptr, &ap);
    va_end(ap); 
    return o_ptr;
}

size_t get_size_o(void *const _self)
{
    struct object_vt_s *const self = _self;
    return self->size; 
}

void *object_ctor(void *_self, va_list *app)
{
    struct object_class_s *self = _self;
    self->a = va_arg(*app, int);
    self->b = va_arg(*app, int);
    return _self;
}
struct object_vt_s object_vt = {
    sizeof(struct object_class_s),
    object_ctor 
};

void *const object = &object_vt;
