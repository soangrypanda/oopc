#include "object.h"
#include "object.r"

void *new_o(void *const _self, ...)
{
    struct object_vt_s *const self = _self; 
    if(!self) {
        return 0;
    }
    void *o_ptr = calloc(1, self->size);
    if(o_ptr == 0 && errno == ENOMEM) {
        exit_error("new_o", ERR_NO);
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
    if(self->vt->dtor) {
        self->vt->dtor(_self);
    } 
    free(_self);
    return 0;
}

void print_o(const void *const _self)
{
    const struct object_class_s *const self = _self;
    if(!self || !self->vt || !self->vt->print) {
        exit_error("print_o", EWRONGOBJ);
    } 
    self->vt->print(_self);
}

void *copy_o(const void *const _self)
{
    const struct object_class_s *const self = _self;
    if(!self || !self->vt || !self->vt->copy) {
        exit_error("copy_o", EWRONGOBJ);
    }
    return self->vt->copy(_self);
}

size_t get_size_o(const void *const _self)
{
    const struct object_vt_s *const self = _self;
    return self->size; 
}

int get_a(const void *const _self)
{
    const struct object_class_s * const self = _self;
    if (!self || self->vt != object ) {
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

void object_print(const void *const _self)
{
    fprintf(stdout, "%d \n", get_a((const struct object_class_s * const) _self));
}

void *object_copy(const void *const _self)
{
    return new_o(object, get_a(_self), 0);
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
    object_print,
    object_copy,
    object_a_getter 
};

void *const object = &object_vt;
