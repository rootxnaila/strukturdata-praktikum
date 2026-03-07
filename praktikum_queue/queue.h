#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} Queue;

void createQueue(Queue *q);
int head(Queue q);
int tail(Queue q);
bool isEmpty(Queue q);
bool isFull();
void enqueue(Queue *q, int element);
int dequeue(Queue *q);

#endif
