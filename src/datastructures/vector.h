#ifndef VECTOR_H
#define VECTOR_H

#include "../base/base.h"
#include <string.h>

// vector
typedef struct vector {
  void *data;
  int datasize;
  // type_t datatype // TODO: Type safety
  int size;
  int maxsize;
  void *datapointer; // points to the next available write spot in the buffer;
  // oop time
  int (*add)(struct vector *self, void *data);
  int (*remove)(struct vector *self, int index);
  void (*reserve)(struct vector *self, int size);
  void *(*at)(struct vector *self, int index);
} vector;

// vector functions
// creates a new vector with given data and datasize in bytes
vector *vector_new(const void *data, int datasize);
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
void *vector_at(vector *self, int index);
// performs a function on every element of the vector
void vector_foreach(vector *self, void *(*func)(void *, void *), void *b);

// Bitset
// like a vector but for true/false

#endif
