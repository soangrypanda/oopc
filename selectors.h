#ifndef OOPC_SELECTORS_H_SENTRY
#define OOPC_SELECTORS_H_SENTRY

#include <stdlib.h>
#include <assert.h>

void * new(const void *_class, ...);
void * delete(void *_self); 
int print(const void *_self);
void *add(const void *_self, const void *_other);

#endif
