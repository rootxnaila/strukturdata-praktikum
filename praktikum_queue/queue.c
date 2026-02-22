#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void createQueue(Queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

bool isEmpty(Queue q) {
    return q.head == NULL;
}

bool isFull() {
    return false; 
}

int head(Queue q) {
    if (isEmpty(q)) return -1;
    return q.head->data;
}

int tail(Queue q) {
    if (isEmpty(q)) return -1;
    return q.tail->data;
}

void enqueue(Queue *q, int element) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = NULL;

    if (isEmpty(*q)) {
        q->head = newNode;
        q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

int dequeue(Queue *q) {
    if (isEmpty(*q)) return -1;

    Node *temp = q->head;
    int value = temp->data;

    q->head = q->head->next;
    free(temp);

    if (q->head == NULL)
        q->tail = NULL;

    return value;
}
