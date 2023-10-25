#include "queue.h"
#include <string.h>

Queue *queue_init(U32 datasize) {
  Queue *q = malloc(sizeof(Queue));
  q->datasize = datasize;
  q->size = 0;
  return q;
}

int queue_push(Queue *q, const void *data) {
  void *d = malloc(sizeof(q->datasize));
  QueueNode *qn = malloc(sizeof(QueueNode));
  qn->next = NULL;
  qn->data = d;
  memcpy(d, data, q->datasize);
  if (!q->front) {
    q->front = qn;
    q->back = qn;
  } else {
    q->back->next = qn;
  }
  q->size++;

  return 0;
}

int queue_pop(Queue *q) {
  if (!q->front) {
    return 1;
  }
  free(q->front->data);
  QueueNode *qn = q->front;
  q->front = qn->next;
  free(qn);
  q->size--;
  return 0;
}

void *queue_top(Queue *q) { return q->front->data; }

QueueNode *queue_topNode(Queue *q) { return q->front; }

const U32 queue_size(Queue *q) { return q->size; }
