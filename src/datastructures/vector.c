#include "vector.h"
#include <malloc/_malloc.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

vector *vector_init(int datasize) {
  vector *v = malloc(sizeof(vector));

  v->datasize = datasize;
  v->size = 0;
  v->maxsize = 2;
  v->data = malloc(datasize * 2);

  return v;
}

int vector_add(vector *self, void *data) {
  // if limit has been reached, resize
  if (self->size == self->maxsize) {
    vector_resize(self);
  }

  memcpy(self->data + self->size * self->datasize, data, self->datasize);
  self->size++;

  return 0;
}

void *vector_at(vector *self, U32 index) {
  return self->data + index * self->datasize;
}

void vector_resize(vector *self) {
  self->data = realloc(self->data, self->datasize * self->size * 2);
}

void vector_reserve(vector *self, int size);

int vector_remove(vector *self, int index);

void vector_foreach(vector *self, void *(*func)(void *, void *), void *b);
