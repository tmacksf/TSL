#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include "../base.h"
#include "string.h"

// doubly linked list
typedef struct d_linkedlist {
  struct d_linkedlist *next;
  struct d_linkedlist *previous;
  void *data;
  // not sure if i need a type specifier
  // void *type; // then have these all match within a list to avoid type errors
} d_linkedlist;

// DLinkedList functions
d_linkedlist *dlist_init(void *data, int datasize);

d_linkedlist *dlist_createnode(void *data, int datasize);

// debugging info
#ifndef DEBUG
int dlist_info(d_linkedlist *head);
#endif // !DEBUG
// adds a node to the start of the list returning pointer to it
d_linkedlist *dlist_addtostart(d_linkedlist *list_node, void *data,
                               int datasize);
// adds a node to the end of the list returning pointer to it. Can take any
// element in the list
d_linkedlist *dlist_addtoend(d_linkedlist *list_node, void *data, int datasize);
// removes a node. If it is the head, it returns the next element as head. if it
// is not head, it linkes the next to the previous
int dlist_removenode(d_linkedlist *node);
// performs function on each element in the list
int dlist_foreach(d_linkedlist *head, void (*func)(d_linkedlist *, void *),
                  void *b);

#endif
