#include <stdio.h>
#include "queue.h"

int main() {
    Queue q;
    createQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Head : %d\n", head(q));
    printf("Tail : %d\n", tail(q));

    printf("Dequeue : %d\n", dequeue(&q));
    printf("Dequeue : %d\n", dequeue(&q));

    return 0;
}
