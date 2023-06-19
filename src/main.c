#include "datastructures.h"
#include "str.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

  int a[] = {200, 6789, 1, 2, 3, 4, 5};

  typedef struct tests {
    int val;
    int anotherval;
  } tests;

  printf("%d, %d\n", a[0], a[1]);

  tests t;
  t.val = 6;
  t.anotherval = 7;
  int v = 7;
  int j = 6;
  int k = 8;
  linkedlist *start = list_createnode(&v, sizeof(v));
  linkedlist *middle = list_addtoend(start, &j, sizeof(j));
  linkedlist *end = list_addtoend(start, &k, sizeof(k));

  printf("Middle node: %d\n", *(int *)start->next->data);
  list_removenode(middle, start);
  printf("Middle node: %d\n", *(int *)start->next->data);
  //   list_info(start);

  // printf("%d", *(int *)(start->next->data));

  return 0;
}
