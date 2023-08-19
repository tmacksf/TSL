#include "vector.h"

Vector *vector_init(int datasize) {
  Vector *v = malloc(sizeof(Vector));

  v->datasize = datasize;
  v->size = 0;
  v->maxsize = 2;
  v->data = malloc(datasize * 2);

  return v;
}

int vector_add(Vector *self, void *data) {
  // if limit has been reached, resize
  if (self->size == self->maxsize) {
    vector_resize(self);
  }

  memcpy(self->data + self->size * self->datasize, data, self->datasize);
  self->size++;

  return 0;
}

void *vector_at(Vector *self, U32 index) {
  return self->data + index * self->datasize;
}

void vector_resize(Vector *self) {
  self->data = realloc(self->data, self->datasize * self->size * 2);
  self->maxsize = self->size * 2;
}

void vector_reserve(Vector *self, int size) {
  if (self->data != NULL) {
    free(self->data);
  }
  self->data = malloc(size * self->datasize);
}

void vector_delete(Vector *self) {
  free(self->data);
  free(self);
}
