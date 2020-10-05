#include <stdio.h>
#include "selectors.h"
#include "object.r"
#include "object.h"

void *new(const void *_class, ...)
{
    struct class *class = _class;
    void *p = calloc(1, class->size);
    assert(p);
    * (struct class**) p = class;
    if(class->ctor) {
        va_list ap;
        va_start(ap, _class);
        p = class->ctor(p, &ap); 
        va_end(ap);
    } 
    return p;
}

void *delete(void *_self)
{
    struct class **self = _self;
    if(self && (*self) && (*self)->dtor)
        self = (*self)->dtor(_self); 
    free(self);
    self = 0;
    return (void *) self;
}

int print(const void *_self)
{
    const struct class * const * self = _self;
    int charpr = 0;
    if(self && (*self) && (*self)->print) 
        charpr = (*self)->print(_self);
    return charpr; 
}

void *add(const void *_self, const void *_other)
{
    const struct class * const *self = _self;
    const struct class * const *other = _other;
    if ((*self) != (*other)) {
        fputs("Trying to add objects of fifferent type!\n", stderr);
        exit(0); 
    }
    int sum = (*self)->add(_self, _other);
    return new(object, sum);
}
