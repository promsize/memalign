/*
 * memalign - Standard-like functions for pointer alignment
 *
 * Copyright (C) 2020-2021 Ingo Albrecht <copyright@promovicz.org>
 */

#ifndef MEMALIGN_H
#define MEMALIGN_H

#include <stdint.h>

#define PTRALIGN(_type, _ptr_ref, _ptr_space) \
    ptralign(__alignof__(_type), sizeof(_type), _ptr_ref, _ptr_space)

static inline void *ptralign(size_t align, size_t size, void **ptr, size_t space) {
	const uintptr_t __intptr = (uintptr_t)ptr;
	const uintptr_t __aligned = (__intptr - 1u + align) & -align;
	const uintptr_t __diff = __aligned - __intptr;
	if ((size + __diff) > space)
		return NULL;
	else {
		space -= __diff;
		return *ptr = (void*)(__aligned);
	}
}

#endif /* !MEMALIGN_H */
