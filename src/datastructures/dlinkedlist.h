#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include "../base/base.h"
#include "string.h"

// doubly linked list
typedef struct DLinkedList {
  struct DLLNode *head;
  struct DLLNode *tail;
  int size;
  int datasize;

  // function pointers
  struct DLLNode *(*append)(struct DLinkedList *, void *);
  struct DLLNode *(*prepend)(struct DLinkedList *, void *);
  void (*clear)(struct DLinkedList *);
  void (*destroy)(struct DLinkedList *);

} DLinkedList;

typedef struct DLLNode {
  struct DLLNode *next;
  struct DLLNode *previous;
  void *data;
  // not sure if i need a type specifier
  // void *type; // then have these all match within a list to avoid type errors
} DLLNode;

// DLinkedList functions
DLinkedList *dlist_init(int datasize);
// Creates a node (not to be used on its own)
DLLNode *dlist_createNode(void *data, int datasize);
// debugging info
int dlist_info(DLinkedList *dll);
// adds a node to the start of the list returning pointer to it
DLLNode *dlist_prepend(DLinkedList *dll, void *data);
// adds a node to the end of the list returning pointer to it. Can take any
// element in the list
DLLNode *dlist_append(DLinkedList *dll, void *data);
// removes node at a given index checking bounds
int dlist_removeNodeAt(DLinkedList *dll, int index);
// removes a given node checking if it exists
int dlist_removeNode(DLinkedList *dll, DLLNode *node);
// performs function on each element in the list
int dlist_foreach(DLinkedList *dll, void (*func)(DLinkedList *, void *),
                  void *b);
// clears a dll
void dlist_clear(DLinkedList *dll);
// delets a dll
void dlist_destroy(DLinkedList *dll);
#endif
