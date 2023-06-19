#include "sorting.h"
#include <stdio.h>

void swap(void *a, void *b, int size) {
  char buffer[size];

  memcpy(buffer, a, size);
  memcpy(a, b, size);
  memcpy(b, buffer, size);
}

int cmp_char(char a, char b) {
  if (a == b) {
    return 0;
  }
  if (a < b)
    return -1;
  else
    return 1;
}

int cmp_int(int a, int b) {
  if (a == b) {
    return 0;
  }
  if (a < b)
    return -1;
  else
    return 1;
}

void quicksort(void *s, int count, int size, void *cmp) {
  if (count < 2)
    return;

  int pivot = count / 2;

  void *i = (int *)s;
  int *j = (int *)s + count * size;

  printf("%p, %d", i, *j);
}
