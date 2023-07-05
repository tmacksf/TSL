#ifndef ARENA_H
#define ARENA_H

#include "../base/base.h"

// Stack allocated arena
typedef struct Arena {
  char *data;
  U64 size;
  U64 capacity;
} Arena;

#define arena_reset(a) (a)->size = 0;
void *arena_alloc(Arena *a, U64 size);

#endif
