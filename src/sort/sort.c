#include "sort.h"

void swap(void *a, void *b, U32 size) {
  char buffer[size];

  memcpy(buffer, a, size);
  memcpy(a, b, size);
  memcpy(b, buffer, size);
}

void quicksort(void *data, U32 count, U32 dataSize,
               int (*cmp)(const void *, const void *, void *), void *extra) {

  // TODO: Some optimisation to make sure the pivot is less than the end of the
  // list and greater than the start?

  if (count < 2)
    return;

  U32 pivot = count / 2;
  U32 i = 1;
  U32 j = count - 1;
  // Don't need to do this but its easier to understand
  swap(data, data + pivot * dataSize, dataSize);

  pivot = 0;
  for (int iter = 1; iter < count; iter++) {
    while (cmp(data + i * dataSize, data, extra) <= 0 && i < dataSize) {
      i++;
    }

    while (cmp(data + j * dataSize, data, extra) >= 0 && j > 0) {
      j--;
    }

    if (i > j)
      break;

    swap(data + i * dataSize, data + j * dataSize, dataSize);
  }

  swap(data, data + j * dataSize, dataSize);
  // front partition
  quicksort(data, j, dataSize, cmp, extra);
  quicksort(data + j * dataSize + dataSize, count - j, dataSize, cmp, extra);
}

void bubblesort(void *data, U32 count, U32 dataSize,
                int (*cmp)(const void *, const void *, void *), void *extra) {

  // pass over the array
  for (int pass = 0; pass < count - 1; pass++) {
    for (int i = 0; i < count - pass; i++) {
      if (cmp(data + i * dataSize, data + (i + 1) * dataSize, extra) > 0) {
        swap(data + i * dataSize, data + (i + 1) * dataSize, dataSize);
      }
    }
  }
}
