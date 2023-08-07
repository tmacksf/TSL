#ifndef VECTOR_H
#define VECTOR_H

#include "../base/base.h"
#include <string.h>

// Vector
typedef struct Vector {
  int datasize;
  int size;
  int maxsize;
  void *data;
} Vector;

// Vector functions
// creates a Vector with the datasize of the type in bytes
Vector *vector_init(int datasize);
// wipes Vector reserving a given number of bytes
void vector_reserve(Vector *self, int size);
// resizes a Vector when it has reached max capacity by allocating a new buffer
// the copying memory and freeing old memory
void vector_resize(Vector *self);
// adds an element to the Vector
int vector_add(Vector *self, void *data);
// removes an element from a Vector
int vector_remove(Vector *self, int index);
// gets the data at an index
void *vector_at(Vector *self, U32 index);
// performs a function on every element of the Vector
// tf
void vector_foreach(Vector *self, void *(*func)(void *, void *), void *b);

// Bitset
// like a Vector but for true/false

#endif
