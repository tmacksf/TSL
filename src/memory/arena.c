#include "arena.h"

void *arena_alloc(Arena *a, U64 size) {
  Assert((a->size + size) < a->capacity);
  void *result = &a->data[a->size];
  a->size += size;

  return result;
}
