#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../base.h"
#include "string.h"

// linked list
typedef struct linkedlist {
  struct ll_node *head;
  // TODO: Decide if this is necessary
  // struct ll_node *tail;
  int size;
  int datasize;

} linkedlist;

// linked list node
typedef struct ll_node {
  struct ll_node *next;
  void *data;
} ll_node;

// Linked list fucntions

// TODO:this
linkedlist *list_init(void *data, int datasize);
// creates a node for a list
ll_node *list_createnode(void *data, int datasize);
// gets the info about the list
int list_info(linkedlist *ll);
// adds a node to the start of the list returning pointer to it
ll_node *list_prepend(linkedlist *ll, void *data);
// adds a node to the end of the list returning pointer to it
ll_node *list_append(linkedlist *ll, void *data);
// removes a node. If it is the head, it returns the next element as head. if it
// is not head, it linkes the next to the previous
ll_node *list_removenode(linkedlist *ll, ll_node *node);
// removes a node at an index using list_removenode (head index = 0). If there
// is no node at the index it returns null, else it returns the previous node
ll_node *list_removenodeat(linkedlist *ll, int index);
// performs function on each element in the list
int list_foreach(linkedlist *ll, void (*func)(linkedlist *, void *), void *b);
// gets an element from a linked list at an index
linkedlist *list_getnodeat(linkedlist *ll, int index);

#endif
