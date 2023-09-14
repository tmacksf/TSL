#include "sort.h"
#include <string.h>

/*
static void swap_byte(void *a, void *b, U32 count) {
  char *x = (char *)a;
  char *y = (char *)b;
  while (count--) {
    char t = *x;
    *x = *y;
    *y = t;
    x += 1;
    y += 1;
  }
}

static void swap_word(void *a, void *b, U32 count) {
  char *x = (char *)a;
  char *y = (char *)b;
  long t[1];

  while (count--) {
    memcpy(t, x, sizeof(long));
    memcpy(x, y, sizeof(long));
    memcpy(y, t, sizeof(long));
    x += sizeof(long);
    y += sizeof(long);
  }
}

void swap(void *a, void *b, U32 size) {
  U32 words = size / sizeof(long);
  U32 bytes = size % sizeof(long);
  swap_word(a, b, words);
  a = (char *)a + words * sizeof(long);
  b = (char *)b + words * sizeof(long);
  swap_byte(a, b, bytes);
}
*/

static inline void swap(void *a, void *b, U32 size) {
  char buffer[128] = {0};

  memcpy(buffer, a, size);
  memcpy(a, b, size);
  memcpy(b, buffer, size);
}

/* TODO: Some optimisation to make sure the pivot is less than the end of
 * the list and greater than the start? */

void quicksort(void *data, U32 count, U32 dataSize,
               int (*cmp)(const void *, const void *)) {
  if (count < 2)
    return;

  U32 pivot = 0;
  U32 lowerIndex = 1;
  U32 upperIndex = count - 1;

  // while (1) {
  for (int i = 0; i < count; i++) {
    while (cmp(data + lowerIndex * dataSize, data) <= 0 && lowerIndex < count) {
      lowerIndex++;
    }
    while (cmp(data + upperIndex * dataSize, data) >= 0 && upperIndex > 0) {
      upperIndex--;
    }
    if (lowerIndex > upperIndex)
      break;

    swap(data + lowerIndex * dataSize, data + upperIndex * dataSize, dataSize);
  }

  swap(data, data + upperIndex * dataSize, dataSize);
  quicksort(data, upperIndex, dataSize, cmp);
  quicksort(data + lowerIndex * dataSize, count - lowerIndex, dataSize, cmp);
}

void bubblesort(void *data, U32 count, U32 dataSize,
                int (*cmp)(const void *, const void *, void *), void *extra) {

  /* pass over the array */
  for (int pass = 0; pass < count - 1; pass++) {
    for (int i = 0; i < count - pass; i++) {
      if (cmp(data + i * dataSize, data + (i + 1) * dataSize, extra) > 0) {
        swap(data + i * dataSize, data + (i + 1) * dataSize, dataSize);
      }
    }
  }
}
