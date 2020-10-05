#include <assert.h>
#include "object.h"
#include "object.r"

struct object_s {
    void * type;
    int val; 
};

void *object_ctor(const void * _self, va_list *app)
{
    struct object_s * self = _self;
    int val = va_arg(*app, int);
    self->val = val;
    return self;
}

void *object_dtor(void *_self)
{
    return _self;
}

int object_print(const void *_self)
{
    struct object_s * self = _self;
    return printf("%d\n", self->val);
}

int object_add(const void *_self, const void *_other)
{
    const struct object_s *self = _self;
    const struct object_s *other = _other;
    return self->val + other->val;
}

static const struct class object_vt = {
    sizeof(struct object_s),
    object_ctor,
    object_dtor, 
    object_print,
    object_add
};


const void *object = &object_vt;
