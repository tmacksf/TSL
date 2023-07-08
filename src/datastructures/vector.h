#ifndef VECTOR_H
#define VECTOR_H

#include "../base/base.h"
#include <string.h>

// vector
typedef struct vector {
  int datasize;
  int size;
  int maxsize;
  void *data;
} vector;

// vector functions
// creates a vector with the datasize of the type in bytes
vector *vector_init(int datasize);
// wipes vector reserving a given number of bytes
void vector_reserve(vector *self, int size);
// resizes a vector when it has reached max capacity by allocating a new buffer
// the copying memory and freeing old memory
void vector_resize(vector *self);
// adds an element to the vector
int vector_add(vector *self, void *data);
// removes an element from a vector
int vector_remove(vector *self, int index);
// gets the data at an index
void *vector_at(vector *self, U32 index);
// performs a function on every element of the vector
void vector_foreach(vector *self, void *(*func)(void *, void *), void *b);

// Bitset
// like a vector but for true/false

#endif
