#ifndef SORTING_H
#define SORTING_H

#include "base.h"
#include <stdlib.h>
#include <string.h>

void swap(void *a, void *b, int size);

// comparisons
int cmp_char(char a, char b);
int cmp_int(int a, int b);
int cmp_long(long a, long b);
int cmp_float(float a, float b);

void quicksort(void *s, int count, int size, void *cmp);

void rsort(); // radixsort

void bubblesort();

void msort(); // mergesort

void hsort(); // heapsort

#endif
