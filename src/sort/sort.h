#ifndef SORTING_H
#define SORTING_H

#include "../base/base.h"
#include <string.h>

#define MAX_DATA_SIZE 10000 /* Max data size */

void swap(void *a, void *b, U32 size);

void quicksort(void *data, U32 count, U32 dataSize,
               int (*cmp)(const void *, const void *, void *), void *extra);

void rsort(); /* radixsort */

void bubblesort(void *data, U32 count, U32 dataSize,
                int (*cmp)(const void *, const void *, void *), void *extra);

void msort(); /* mergesort */

void hsort(); /* heapsort */
#endif
