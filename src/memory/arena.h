#ifndef ARENA_H
#define ARENA_H

#include "../base.h"

// TODO: Make this actually do stuff

typedef struct Arena {
  char *data;
  u64 size;
  u64 capacity;
} Arena;

/* creates an arena of given capacity in bytes */
Arena *arena_init(u32 capacity);

/* creates a buffer inside of the arena of given size */
void *arena_alloc(Arena *a, u64 size);

#endif
