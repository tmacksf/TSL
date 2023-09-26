#ifndef ARENA_H
#define ARENA_H

#include "../base.h"

// TODO: Make this actually do stuff

typedef struct Arena {
  char *data;
  U64 size;
  U64 capacity;
} Arena;

/* creates an arena of given capacity in bytes */
Arena *arena_init(U32 capacity);

/* creates a buffer inside of the arena of given size */
void *arena_alloc(Arena *a, U64 size);

#endif
