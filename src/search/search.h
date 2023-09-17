#ifndef SEARCH_H
#define SEARCH_H

#include "../base.h"

int binarySearch(const void *key, const void *arr, U32 length, U32 dataSize,
                 int (*cmp)(const void *, const void *));

#endif
