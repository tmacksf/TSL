#include "datastructures/dlinkedlist.h"
#include "datastructures/vector.h"
#include "str/str.h"
#include <stdio.h>
#include <stdlib.h>

void *printint(void *i, void *b) {
  printf("int: %d\n", *(int *)i);
  return 0;
}

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
  int v = 6;
  int j = 7;
  int k = 8;
  vector *vec = vector_new(&v, sizeof(int));
  vec->add(vec, &j);
  vec->add(vec, &k);
  printf("%lu, %p %p %d\n", sizeof(int), vec->data, vec->datapointer,
         vec->size);
  vec->remove(vec, 1);
  printf("%lu, %p %p %d\n", sizeof(int), vec->data, vec->datapointer,
         vec->size);

  vector_foreach(vec, printint, NULL);

  // printf("%d", *(int *)(start->next->data));

  return 0;
}
