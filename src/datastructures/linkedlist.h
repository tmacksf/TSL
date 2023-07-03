#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../base.h"
#include "string.h"

// linked list
typedef struct LinkedList {
  struct LLNode *head;
  // TODO: Test to amke sure this is worth having (might cause unnecessary
  // annoyance)
  struct LLNode *tail;
  int size;
  int datasize;

  // Function pointers
  struct LLNode *(*append)(struct LinkedList *, void *);
  struct LLNode *(*prepend)(struct LinkedList *, void *);
  struct LLNode *(*at)(struct LinkedList *, int);
  int (*removeAt)(struct LinkedList *, int);
  int (*remove)(struct LinkedList *, struct LLNode *);

} LinkedList;

// linked list node
typedef struct LLNode {
  struct LLNode *next;
  void *data;
} LLNode;

// Linked list fucntions

// initialises a linked list of size 0 with defined datasize
LinkedList *list_init(int datasize);
// creates a node for a list from data (not to be used on its own)
LLNode *list_createNode(void *data, int datasize);
// gets the info about the list
int list_info(LinkedList *ll);
// adds a node to the start of the list returning pointer to it
LLNode *list_prepend(LinkedList *ll, void *data);
// adds a node to the end of the list returning pointer to it
LLNode *list_append(LinkedList *ll, void *data);
// removes a given node from the list. If successful, returns 0, otherwise
// returns -1
int list_removeNode(LinkedList *ll, LLNode *node);
// removes a node at an index using list_removenode (head index = 0). If there
// is no node at the index it returns null, else it returns the previous node
int list_removeNodeAt(LinkedList *ll, int index);
// performs function on each element in the list
int list_forEach(LinkedList *ll, void (*func)(LLNode *, void *), void *b);
// gets an element from a linked list at an index
LLNode *list_getNodeAt(LinkedList *ll, int index);
// clears the list of all objects
void list_clear(LinkedList *ll);
// deletes the list
void list_destroy(LinkedList *ll);
// gets the object at a given index
LLNode *list_at(LinkedList *ll, int index);

#endif
