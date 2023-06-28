#include "dlinkedlist.h"

d_linkedlist *dlist_init(int datasize) {
  d_linkedlist *list = malloc(sizeof(d_linkedlist));
  list->tail = NULL;
  list->head = NULL;
  list->size = 0;
  list->datasize = datasize;

  return list;
}

dll_node *dlist_createnode(void *data, int datasize) {
  dll_node *node = malloc(sizeof(dll_node));
  node->data = malloc(datasize);
  memcpy(node->data, data, datasize);
  node->next = NULL;
  node->previous = NULL;

  return node;
}

int dlist_prepend(d_linkedlist *dll, void *data) {
  dll_node *node = dlist_createnode(data, dll->datasize);

  dll->head = node;

  if (!dll->size)
    dll->tail = node;

  dll->size++;

  return 0;
}

int dlist_append(d_linkedlist *dll, void *data) {
  dll_node *node = dlist_createnode(data, dll->datasize);

  dll->tail = node;

  if (!dll->size)
    dll->head = node;

  dll->size++;

  return 0;
}

int dlist_removenode(d_linkedlist *dll, int index) {
  if (index >= dll->size) {
    printf("Out of bounds of dll");

    return -1;
  }

  // TODO: If node == head, if node == tail, if node == head && node == tail
  dll_node *node = dll->head;
  for (int i = 0; i < index; i++) {
    node = node->next;
  }

  free(node->data);

  if (node == dll->head && node->next) {

  } else if (node == dll->head && node->next == NULL) {

  } else if (node->next == NULL) {

  } else {
  }

  node->next->previous = node->previous;
  node->previous->next = node->next;
  free(node);

  return 0;
}
