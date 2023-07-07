#include "vector.h"
#include <string.h>

vector *vector_init(int datasize) {
  vector *v = malloc(sizeof(vector));
  v->datasize = datasize;
  v->size = 0;
  v->maxsize = 2;
  v->data = malloc(datasize * 2);
  v->datapointer = v->data;

  // function pointers
  v->add = *vector_add;
  v->remove = *vector_remove;
  v->reserve = *vector_reserve;
  v->at = *vector_at;

  return v;
}

vector *vector_new(const void *data, int datasize) {
  // reserves two
  vector *v = malloc(sizeof(vector));

  v->datasize = datasize;
  v->size = 1;
  // allocating twice the necessary data size
  v->data = malloc(datasize * 2);
  memcpy(v->data, data, datasize);
  v->datapointer = (v->data) + datasize;

  // function pointers
  v->add = *vector_add;
  v->remove = *vector_remove;
  v->reserve = *vector_reserve;
  v->at = *vector_at;

  return v;
}

void vector_reserve(vector *self, int size) {
  void *data = malloc(self->datasize * size);
  self->data = data;
}

void vector_resize(vector *self) {
  void *new_data = malloc(self->datasize * 2 * self->size);
  memcpy(new_data, self->data, self->datasize);
  free(self->data);
  self->data = new_data;
  self->maxsize = self->maxsize * 2;
}

int vector_add(vector *self, void *data) {
  // reserve twice the data if vector is max size
  if (self->size == self->maxsize) {
    vector_resize(self);
  }

  memcpy(self->datapointer, data, self->datasize);
  self->size++;
  self->datapointer += self->datasize;
  // no need to do any unnecessary resizing

  return 0;
}

void *vector_at(vector *self, int index) {
  return (self->data + index * self->datasize);
}

int vector_remove(vector *self, int index) {
  // TODO: Make sure this works (the memory can be overwritten safely)

  memcpy(self->data + index * self->datasize,
         self->data + (index + 1) * self->datasize, self->size - (index + 1));
  // memcpy(vector_at(self, index), vector_at(self, index + 1), self->datasize *
  // (self->size - index));

  self->size -= 1;
  self->datapointer -= self->datasize;

  return 0;
}

void vector_foreach(vector *self, void *(*func)(void *, void *), void *b) {
  for (int i = 0; i < self->size; i++) {
    func(self->data + (self->datasize * i), b);
  }
}
