#ifndef OOPC_OBJECT_H_SENTRY
#define OOPC_OBJECT_H_SENTRY

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

extern void *const object;

void *new_o(void *const _self, ...);
size_t get_size_o(void *const _self);
#endif
