#include "object.h"
#include "object.r"
#include "oopcerr.h"

void *new_o(void *const _self, ...)
{
    struct object_vt_s *const self = _self; 
    if(!self) {
        return 0;
    }
    void *o_ptr = calloc(1, self->size);
    if(o_ptr == 0 && errno == ENOMEM) {
        exit_error("new_o", ERR_NO );
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

void *delete_o(void *const _self)
{
    struct object_class_s *const self = _self;
    if(!self || !self->vt) {
        exit_error("delete_o", EWRONGOBJ); 
    }
    
    return 0;
}

size_t get_size_o(const void *const _self)
{
    const struct object_vt_s *const self = _self;
    return self->size; 
}

int get_a(const void *const _self)
{
    const struct object_class_s * const self = _self;
    if (!self || !self->vt || !self->vt->a_getter) {
        exit_error("get_a", EWRONGOBJ);
    }
    return self->vt->a_getter(_self);
}

void *object_ctor(void *const _self, va_list *app)
{
    struct object_class_s *const self = _self;
    self->a = va_arg(*app, int);
    self->b = va_arg(*app, int);
    return _self;
}

void *object_dtor(void *const _self)
{
    return 0;
}

int object_a_getter(const void *const _self)
{
    const struct object_class_s *const self = _self;
    return self->a;
}




struct object_vt_s object_vt = {
    sizeof(struct object_class_s),
    object_ctor,
    object_dtor,
    object_a_getter 
};

void *const object = &object_vt;
