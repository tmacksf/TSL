#ifndef SORTING_H
#define SORTING_H

#include "../base.h"
#include <string.h>

void swap(void *a, void *b, int size);

void quicksort(void *s, int count, int size,
               int (*cmp)(const void *, const void *, void *), void *extra);

void rsort(); // radixsort

void bubblesort();

void msort(); // mergesort

void hsort(); // heapsort

#endif
