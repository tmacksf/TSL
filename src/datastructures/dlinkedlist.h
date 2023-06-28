#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include "../base.h"
#include "string.h"

// doubly linked list
typedef struct d_linkedlist {
  struct dll_node *head;
  struct dll_node *tail;
  int size;
  int datasize;

} d_linkedlist;

typedef struct dll_node {
  struct dll_node *next;
  struct dll_node *previous;
  void *data;
  // not sure if i need a type specifier
  // void *type; // then have these all match within a list to avoid type errors
} dll_node;

// DLinkedList functions
d_linkedlist *dlist_init(int datasize);

dll_node *dlist_createnode(void *data, int datasize);

// debugging info
int dlist_info(d_linkedlist *dll);
// adds a node to the start of the list returning pointer to it
int dlist_prepend(d_linkedlist *dll, void *data);
// adds a node to the end of the list returning pointer to it. Can take any
// element in the list
int dlist_append(d_linkedlist *dll, void *data);
// removes node at a given index checking bounds
int dlist_removenode(d_linkedlist *list, int index);
// performs function on each element in the list
int dlist_foreach(d_linkedlist *head, void (*func)(d_linkedlist *, void *),
                  void *b);

#endif
