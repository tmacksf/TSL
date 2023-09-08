#include "search.h"

int binarySearch(const void *key, const void *arr, U32 length, U32 dataSize,
                 int (*cmp)(const void *, const void *)) {
  U32 lower = 0;
  U32 upper = length;
  U32 index = length / 2;

  /* TODO: Make sure is right */
  int iterations = length / 2;

  for (int i = 0; i < iterations; i++) {
    if (cmp(arr + index * sizeof(int), key) == 0) {
      return index;
    } else if (cmp(arr + index * sizeof(int), key) < 0) {
      /* if index is less than key */
      lower = index;
      index = (lower + upper) / 2;
    } else {
      upper = index;
      index = (lower + upper) / 2;
    }
  }

  return -1;
}
