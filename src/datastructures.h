/* data structures */

#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include "base.h"

// linked list
typedef struct linkedlist {
  struct linkedlist *next;
  void *data;
  // not sure if i need a type specifier
  // type_t type; // then have these all match within a list to avoid type
  // errors
  // TODO: Figure out how to make these type safe with a checker that looks
  // every time a new node is added
} linkedlist;

// Linked list fucntions

// creates a node for a list
linkedlist *list_createnode(void *data, int datasize);
// gets the info about the list
int list_info(linkedlist *head);
// adds a node to the start of the list returning pointer to it
linkedlist *list_addtostart(linkedlist *head, void *data, int datasize);
// adds a node to the end of the list returning pointer to it
linkedlist *list_addtoend(linkedlist *head, void *data, int datasize);
// removes a node. If it is the head, it returns the next element as head. if it
// is not head, it linkes the next to the previous
linkedlist *list_removenode(linkedlist *node, linkedlist *head);
// performs function on each element in the list
int list_foreach(linkedlist *head, void (*func)(linkedlist *ll, void *optional),
                 void *optional_info);

// doubly linked list
typedef struct d_linkedlist {
  struct d_linkedlist *next;
  struct d_linkedlist *previous;
  void *data;
  // not sure if i need a type specifier
  // void *type; // then have these all match within a list to avoid type errors
} d_linkedlist;

// DLinkedList functions

// vector
typedef struct vector {
  void *data;
  int size;
} vector;

#endif
