#ifndef SEARCH_H
#define SEARCH_H

#include "../base.h"

int binarySearch(const void *key, const void *arr, u32 length, u32 dataSize,
                 int (*cmp)(const void *, const void *));

#endif
