#include "dlinkedlist.h"

DLinkedList *dlist_init(int datasize) {
  DLinkedList *list = malloc(sizeof(DLinkedList));
  list->tail = NULL;
  list->head = NULL;
  list->size = 0;
  list->datasize = datasize;

  return list;
}

DLLNode *dlist_createnode(void *data, int datasize) {
  DLLNode *node = malloc(sizeof(DLLNode));
  node->data = malloc(datasize);
  memcpy(node->data, data, datasize);
  node->next = NULL;
  node->previous = NULL;

  return node;
}

DLLNode *dlist_prepend(DLinkedList *dll, void *data) {
  DLLNode *node = dlist_createnode(data, dll->datasize);

  DLLNode *temp = dll->head;
  // TODO: Test
  dll->head = node;
  dll->head->next = temp;

  if (!dll->size)
    dll->tail = node;

  dll->size++;

  return node;
}

DLLNode *dlist_append(DLinkedList *dll, void *data) {
  DLLNode *node = dlist_createnode(data, dll->datasize);

  if (!dll->size)
    dll->head = node;
  else {
    dll->tail->next = node;
  }
  dll->tail = node;

  dll->size++;

  return node;
}

int dlist_removeNodeAt(DLinkedList *dll, int index) {
  // out of bounds
  if (dll->size <= index) {
    // TODO: Errors
    printf("Out of bounds");
    return -1;
  }

  DLLNode *node = dll->head;
  for (int i = 0; i < index; i++) {
    node = node->next;
  }
  dlist_removeNode(dll, node);

  return 0;
}
int dlist_removeNode(DLinkedList *dll, DLLNode *node) {
  // TODO: Decide if I want to check if node is in the list
#ifdef DEBUG
  int found = 0;
  DLLNode *looking = head;
  for (int i = 0; i < dll->size; i++) {
    if (looking == node)
      found = 1;
  }

  if (!found) {
    prinft("Not found");
    return -1;
  }
#endif
  free(node->data);

  // if the node is the head and there is a next node
  if (node == dll->head && node->next) {
    dll->head = node->next;
    dll->head->previous = NULL;
  }
  // if this node is the only one in the list
  else if (node == dll->head && node->next == NULL) {
    dll->head = NULL;
    dll->tail = NULL;
  }
  // if this node is not the head and is the tail
  else if (node->next == NULL) {
    dll->tail = node->previous;
    node->previous->next = NULL;
  }
  // the node is not head/tail
  else {
    node->previous->next = node->next;
    node->next->previous = node->previous;
  }
  dll->size--;
  free(node);

  return 0;
}

void dlist_clear(DLinkedList *dll) {
  DLLNode *node = dll->head;
  while (node->next) {
    free(node->data);
    DLLNode *temp = node->next;
    free(node);
    node = temp;
  }
}
void dlist_destroy(DLinkedList *dll) {
  dlist_clear(dll);
  free(dll);
}
