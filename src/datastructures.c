#include "datastructures.h"
#include <string.h>

linkedlist *list_createnode(void *data, int datasize) {
  linkedlist *l = malloc(sizeof(linkedlist));
  l->data = malloc(datasize);
  memcpy(l->data, data, datasize);
  // l->data = data;
  l->next = NULL;

  return l;
}

linkedlist *list_addtostart(linkedlist *head, void *data, int datasize) {
  linkedlist *new_node = list_createnode(data, datasize);

  new_node->next = head;

  return new_node;
}

linkedlist *list_addtoend(linkedlist *head, void *data, int datasize) {
  linkedlist *new_node = list_createnode(data, datasize);
  printf("%d\n", *(int *)new_node->data);

  linkedlist *node = head;

  while (node->next) {
    node = node->next;
  }

  node->next = new_node;

  return new_node;
}

int list_foreach(linkedlist *head, void (*func)(linkedlist *ll, void *optional),
                 void *optional_info) {
  linkedlist *node = head;
  while (node) {
    func(node, optional_info);

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
