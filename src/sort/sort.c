#include "sort.h"

void swap(void *a, void *b, int size) {
  char buffer[size];

  memcpy(buffer, a, size);
  memcpy(a, b, size);
  memcpy(b, buffer, size);
}

void quicksort(void *s, int count, int size,
               int (*cmp)(const void *, const void *, void *), void *extra) {

  if (count < 2)
    return;

  int pivot = count / 2;

  int i = 0;
  int j = size;

  while (i < j) {
  }
}
