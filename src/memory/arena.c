#include "arena.h"

Arena *arena_init(u32 capacity) {
  Arena *arena = malloc(sizeof(Arena));
  arena->data = malloc(capacity);
  arena->capacity = capacity;
  arena->size = 0;
  return arena;
}

void *arena_alloc(Arena *a, u64 size) {
  Assert((a->size + size) < a->capacity);
  void *result = &a->data[a->size];
  a->size += size;

  return result;
}
