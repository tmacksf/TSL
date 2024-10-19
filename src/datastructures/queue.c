#include "queue.h"
#include <string.h>

Queue *queue_init(u32 datasize) {
  Queue *q = malloc(sizeof(Queue));
  q->datasize = datasize;
  q->size = 0;
  return q;
}

int queue_push(Queue *q, const void *data) {
  QueueNode *qn = malloc(sizeof(QueueNode));
  if (qn == NULL) {
    return -1;
  }

  qn->next = NULL;
  qn->data = malloc(q->datasize);
  if (qn->data == NULL) {
    return -1;
  }
  memcpy(qn->data, data, q->datasize);
  if (!q->size) {
    q->front = qn;
    q->back = qn;
  } else {
    q->back->next = qn;
    q->back = qn;
  }
  q->size++;

  return 0;
}

int queue_pop(Queue *q) {
  if (!q->front)
    return 1;

  QueueNode *qn = q->front;
  q->front = qn->next;
  free(qn->data);
  free(qn);
  q->size--;
  if (q->size == 0) {
    q->back = NULL;
    q->front = NULL;
  }
  return 0;
}

void *queue_top(Queue *q) { return q->front->data; }

QueueNode *queue_topNode(Queue *q) { return q->front; }

const u32 queue_size(Queue *q) { return q->size; }
