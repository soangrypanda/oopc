#ifndef OOPC_OBJECT_H_SENTRY
#define OOPC_OBJECT_H_SENTRY

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include "oopcerr.h"

extern void *const object;

void *new_o(void *const _self, ...);
void *delete_o(void **_self);
void print_o(const void *const _self);
void *copy_o(const void *const _self);
int  compare_o(const void *const _self, const void *const _other);
void *add_o(const void *const _self, const void *const _other);
void *sub_o(const void *const _self, const void *const _other);
void *mult_o(const void *const _self, const void *const _other);
void *div_o(const void *const _self, const void *const _other);

size_t get_size_o(const void *const _self);


#endif
