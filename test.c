
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memalign.h"

int main(void) {
  char *p;
  uint8_t u8;
  uint16_t u16;
  uint32_t u32;
  uint64_t u64;

  p = (char *)&u8;
  assert(PTRALIGN(uint8_t, p, sizeof(u8)) == p);
  assert(PTRALIGN(uint8_t, p, sizeof(u8) - 1) == NULL);
  p = (char *)&u16;
  assert(PTRALIGN(uint16_t, p, sizeof(u16)) == p);
  assert(PTRALIGN(uint16_t, p, sizeof(u16) - 1) == NULL);
  assert(PTRALIGN(uint16_t, p - 1, sizeof(u16) + 1) == p);
  p = (char *)&u32;
  assert(PTRALIGN(uint32_t, p, sizeof(u32)) == p);
  assert(PTRALIGN(uint32_t, p, sizeof(u32) - 1) == NULL);
  assert(PTRALIGN(uint32_t, p - 1, sizeof(u32) + 1) == p);
  assert(PTRALIGN(uint32_t, p - 2, sizeof(u32) + 2) == p);
  assert(PTRALIGN(uint32_t, p - 3, sizeof(u32) + 3) == p);
  p = (char *)&u64;
  assert(PTRALIGN(uint64_t, p, sizeof(u64)) == p);
  assert(PTRALIGN(uint64_t, p, sizeof(u64) - 1) == NULL);
  assert(PTRALIGN(uint64_t, p - 1, sizeof(u64) + 1) == p);
  assert(PTRALIGN(uint64_t, p - 2, sizeof(u64) + 2) == p);
  assert(PTRALIGN(uint64_t, p - 3, sizeof(u64) + 3) == p);

  puts("All tests succeeded.");

  return 0;
}
