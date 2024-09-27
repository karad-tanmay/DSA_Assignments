#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(){
    queue q;
    init(&q);
    printf("Is Empty: %d\n", isEmpty(q));
    printf("Length of queue: %d\n", len(q));
    enqueue(&q, 10);
    enqueue(&q, 15);
    enqueue(&q, 11);
    enqueue(&q, 12);
    enqueue(&q, 13);
    displayQueue(q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    printf("Front: %d\n", peekFront(q));
    printf("Rear: %d\n", peekRear(q));
    displayQueue(q);
    clearQueue(&q);
    printf("test0\n");
    return 0;
}