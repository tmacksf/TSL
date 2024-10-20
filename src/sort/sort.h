#ifndef SORTING_H
#define SORTING_H

#include "../base.h"
#include <string.h>

#define MAX_DATA_SIZE 1000 /* Max data size */

void quicksort(void *data, u32 count, u32 dataSize,
               int (*cmp)(const void *, const void *));

void rsort(); /* radixsort */

void bubblesort(void *data, u32 count, u32 dataSize,
                int (*cmp)(const void *, const void *, void *), void *extra);

void msort(); /* mergesort */

void hsort(); /* heapsort */
#endif
