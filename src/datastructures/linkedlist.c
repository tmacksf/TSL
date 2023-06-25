#include "linkedlist.h"

linkedlist *list_init(void *data, int datasize) {
  linkedlist *ll = malloc(sizeof(linkedlist));
  ll->datasize = datasize;
  ll->size = 1;
  ll->head = list_createnode(data, datasize);

  return ll;
}

ll_node *list_createnode(void *data, int datasize) {
  ll_node *l = malloc(sizeof(ll_node));
  l->data = malloc(datasize);
  memcpy(l->data, data, datasize);
  // l->data = data;
  l->next = NULL;

  return l;
}

void list_addtostart(linkedlist *ll, void *data) {
  ll_node *new_node = list_createnode(data, datasize);

  new_node->next = head;

  return new_node;
}

linkedlist *list_addtoend(linkedlist *head, void *data, int datasize) {
  linkedlist *new_node = list_createnode(data, datasize);

  linkedlist *node = head;

  while (node->next) {
    node = node->next;
  }

  node->next = new_node;

  return new_node;
}

int list_foreach(linkedlist *head, void (*func)(linkedlist *, void *),
                 void *b) {
  linkedlist *node = head;
  while (node) {
    func(node, b);

    node = node->next;
  }

  return 0;
}

int list_info(linkedlist *head) {

  int node_count = 1;

  linkedlist *node = head->next;
  while (node) {
    node_count++;

    node = node->next;
  }

  printf("Node count: %d \n", node_count);

  return 0;
}

linkedlist *list_removenode(linkedlist *node, linkedlist *head) {
  // if its the head and there is a next node
  if (head == node && node->next) {
    linkedlist *new_head = node->next;
    free(node->data);
    free(node);
    return new_head;
  }
  // if there is no next node and it is the head
  else if (head == node && node->next == NULL) {
    free(node->data);
    free(node);
    return NULL;
  }
  // if it is not the head and there is a next node
  else if (head != node && node->next) {
    // find the previous one
    linkedlist *previous_node = head;
    int flag = 1;
    while (flag) {
      if (node == previous_node->next) {
        flag = 0;
        previous_node->next = node->next;
        free(node->data);
        free(node);
        return previous_node;
      } else {
        previous_node = previous_node->next;
      }
    }
  }
  // if its not the head and there is no next node
  else if (head != node && node->next == NULL) {
    linkedlist *previous_node = head;
    int flag = 1;
    while (flag) {
      if (node == previous_node->next) {
        flag = 0;
        previous_node->next = NULL;
        free(node->data);
        free(node);
        return 0;
      } else {
        previous_node = previous_node->next;
      }
    }
  }

  return NULL;
}

linkedlist *list_removenodeat(linkedlist *head, int index) {
  // TODO: Test
  linkedlist *noderemoving = head;
  int found = 1;
  for (int i = 0; i < index; i++) {
    if (noderemoving->next) {
      noderemoving = noderemoving->next;
    } else {
      found = 0;
      break;
    }
  }
  linkedlist *before = list_removenode(noderemoving, head);

  if (!found)
    return NULL;
  else
    return before;
}

linkedlist *list_getnodeat(linkedlist *head, int index) {
  // TODO: Test
  linkedlist *node = head;

  int found = 1;
  for (int i = 0; i < index; i++) {
    if (node->next)
      node = node->next;
    else {
      found = 0;
      break;
    }
  }

  if (!found)
    return NULL;
  else
    return node;
}
