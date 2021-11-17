
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ptralign.h"

int main(void) {
  void *p;
  uint8_t u8;
  uint16_t u16;
  uint32_t u32;
  uint64_t u64;

  p = &u8;
  assert(PTRALIGN(uint8_t, p, sizeof(u8)) == p);
  assert(PTRALIGN(uint8_t, p, sizeof(u8) - 1) == NULL);
  p = &u16;
  assert(PTRALIGN(uint16_t, p, sizeof(u16)) == p);
  assert(PTRALIGN(uint16_t, p, sizeof(u16) - 1) == NULL);
  p = &u32;
  assert(PTRALIGN(uint32_t, p, sizeof(u32)) == p);
  assert(PTRALIGN(uint32_t, p, sizeof(u32) - 1) == NULL);
  p = &u64;
  assert(PTRALIGN(uint64_t, p, sizeof(u64)) == p);
  assert(PTRALIGN(uint64_t, p, sizeof(u64) - 1) == NULL);

  puts("All tests succeeded.");

  return 0;
}
