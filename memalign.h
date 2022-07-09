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

static inline uintptr_t memalign(size_t align, size_t size, uintptr_t value, size_t space) {
  const uintptr_t aligned = (value - 1u + align) & -align;
  const uintptr_t delta = aligned - value;
  if ((size + delta) > space)
    return 0;
  else {
    space -= delta;
    return aligned;
  }
}

static inline void *ptralign(size_t align, size_t size, void *value, size_t space) {
  return (void*)memalign(align, size, (uintptr_t)value, space);
}

static inline size_t sizealign(size_t align, size_t size, size_t value, size_t space) {
  return (size_t)memalign(align, size, (uintptr_t)value, space);
}

#endif /* !MEMALIGN_H */
