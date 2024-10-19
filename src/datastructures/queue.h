#ifndef QUEUE_H
#define QUEUE_H

#include "../base.h"

typedef struct QueueNode {
  void *data;
  struct QueueNode *next;
} QueueNode;

typedef struct Queue {
  QueueNode *front;
  QueueNode *back;
  u32 size;
  u32 datasize;
} Queue;

Queue *queue_init(u32 datasize);

int queue_push(Queue *q, const void *data);

int queue_pop(Queue *q);

void *queue_top(Queue *q);

QueueNode *queue_topNode(Queue *q);

const u32 queue_size(Queue *q);

#endif
