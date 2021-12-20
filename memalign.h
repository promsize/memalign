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
  const uintptr_t uptr = (uintptr_t)ptr;
  const uintptr_t aligned = (uptr - 1u + align) & -align;
  const uintptr_t diff = aligned - uptr;
  if ((size + diff) > space)
    return NULL;
  else {
    space -= diff;
    return *ptr = (void*)aligned;
  }
}

#endif /* !MEMALIGN_H */
