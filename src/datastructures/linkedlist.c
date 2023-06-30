#include "LinkedList.h"

LinkedList *list_init(int datasize) {
  LinkedList *ll = malloc(sizeof(LinkedList));
  ll->datasize = datasize;
  ll->size = 0;
  ll->head = NULL;
  ll->tail = NULL;

  ll->append = list_append;
  ll->prepend = list_prepend;
  ll->at = list_at;
  ll->removeAt = list_removeNodeAt;
  ll->remove = list_removeNode;

  return ll;
}

LLNode *list_createNode(void *data, int datasize) {
  LLNode *l = malloc(sizeof(LLNode));
  l->data = malloc(datasize);
  // memcpy(l->data, data, datasize);
  l->data = data;
  l->next = NULL;

  return l;
}

LLNode *list_prepend(LinkedList *ll, void *data) {
  LLNode *new_node = list_createNode(data, ll->datasize);

  new_node->next = ll->head;
  ll->head = new_node;
  ll->size++;

  if (!ll->size) {
    ll->tail = new_node;
  }

  return new_node;
}

LLNode *list_append(LinkedList *ll, void *data) {
  LLNode *new_node = list_createNode(data, ll->datasize);

  ll->tail->next = new_node;
  ll->tail = new_node;
  ll->size++;

  // TODO: find a way to reduce branching at these places
  if (!ll->size) {
    ll->head = new_node;
  }

  return new_node;
}

int list_removeNode(LinkedList *ll, LLNode *node) {
  // if its the head and there is a next node
  if (ll->head == node && node->next) {
    ll->head = node->next;
    ll->size--;
    free(node->data);
    free(node);
    return 0;
  }
  // if there is no next node and it is the head
  else if (ll->head == node && node->next == NULL) {
    ll->head = NULL;
    ll->tail = NULL;
    free(node->data);
    free(node);
    ll->size = 0;
    return 0;
  }
  // if it is not the head and there is a next node
  else if (ll->head != node && node->next) {
    // find the previous one
    LLNode *previous_node = ll->head;
    for (int i = 0; i < ll->size; i++) {
      if (node == previous_node->next) {
        previous_node->next = node->next;
        free(node->data);
        free(node);
        ll->size--;
        return 0;
      } else {
        previous_node = previous_node->next;
      }
    }
  }
  // if its not the head and there is no next node
  else if (ll->head != node && node->next == NULL) {
    LLNode *previous_node = ll->head;
    for (int i = 0; i < ll->size; i++) {
      if (node == previous_node->next) {
        previous_node->next = NULL;
        ll->tail = previous_node;
        free(node->data);
        free(node);
        ll->size--;
        return 0;
      } else {
        previous_node = previous_node->next;
      }
    }
  }

  return -1;
}

int list_removeNodeAt(LinkedList *ll, int index) {
  // TODO: Test
  LLNode *noderemoving = ll->head;
  int found = 1;
  if (index >= ll->size) {
#ifdef DEBUG
    printf("out of bounds for list");
#endif // ifdef DEBUG
    return -1;
  }

  if (!found)
    return -1;

  int deleted = list_removeNode(ll, noderemoving);
  return deleted;
}

int list_forEach(LinkedList *ll, void (*func)(LLNode *, void *), void *b) {
  LLNode *node = ll->head;
  while (node) {
    func(node, b);

    node = node->next;
  }

  return 0;
}

int list_info(LinkedList *ll) {
  printf("Node count: %d \n", ll->size);

  return 0;
}

LLNode *list_getNodeAt(LinkedList *ll, int index) {
  if (index >= ll->size) {
#ifdef DEBUG
    printf("Out of bounds for list");
#endif
    return NULL;
  }

  LLNode *node = ll->head;
  for (int i = 0; i < index; i++) {
    node = node->next;
  }

  return node;
}

void list_clear(LinkedList *ll) {
  LLNode *node = ll->head;
  for (int i = 0; i < ll->size; i++) {
    free(node->data);
    LLNode *temp = node;
    node = node->next;
    free(temp);
  }
  ll->size = 0;
  ll->head = NULL;
  ll->tail = NULL;
}

void list_destroy(LinkedList *ll) {
  list_clear(ll);
  free(ll);
}

LLNode *list_at(LinkedList *ll, int index) {
  LLNode *noderemoving = ll->head;
  if (index >= ll->size) {
#ifdef DEBUG
    printf("out of bounds for list");
#endif // ifdef DEBUG
    return NULL;
  }

  LLNode *node = ll->head;
  for (int i = 0; i < index; i++) {
    node = node->next;
  }
  return node;
}
