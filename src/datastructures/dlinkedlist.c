#include "dlinkedlist.h"

d_linkedlist *dlist_init(void *data, int datasize) {
  return dlist_createnode(data, datasize);
}

d_linkedlist *dlist_createnode(void *data, int datasize) {
  d_linkedlist *node = malloc(sizeof(d_linkedlist));
  node->data = malloc(datasize);
  memcpy(node->data, data, datasize);
  node->next = NULL;
  node->previous = NULL;

  return node;
}

d_linkedlist *dlist_addtostart(d_linkedlist *list_node, void *data,
                               int datasize) {
  d_linkedlist *node = dlist_createnode(data, datasize);
  while (list_node->previous) {
    list_node = list_node->previous;
  }
  node->next = list_node;
  list_node->previous = node;

  return node;
}

d_linkedlist *dlist_addtoend(d_linkedlist *list_node, void *data,
                             int datasize) {
  d_linkedlist *node = dlist_createnode(data, datasize);

  while (list_node->next) {
    list_node = list_node->next;
  }
  list_node->next = node;
  node->previous = list_node;

  return node;
}

int dlist_removenode(d_linkedlist *node) {
  free(node->data);

  node->next->previous = node->previous;
  node->previous->next = node->next;
  free(node);

  return 0;
}
