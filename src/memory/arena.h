#ifndef ARENA_H
#define ARENA_H

#include "../base.h"

// TODO: Make this actually do stuff

typedef struct Arena {
  char *data;
  U64 size;
  U64 capacity;
} Arena;

Arena *arena_init(U32 size);

void *arena_alloc(Arena *a, U64 size);

#endif
