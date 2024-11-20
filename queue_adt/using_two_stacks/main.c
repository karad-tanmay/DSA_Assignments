#include <stdio.h>
#include "queue.c"

int main(){
    queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 15);
    enqueue(&q, 11);
    printf("dequeue:%d\n", dequeue(&q));
    printf("dequeue:%d\n", dequeue(&q));
    enqueue(&q, 7);
    enqueue(&q, 0);
    enqueue(&q, 9);
    printf("dequeue:%d\n", dequeue(&q));
    printf("dequeue:%d\n", dequeue(&q));
    peekFront(q);
    peekRear(q);
    printf("isEmpty: %d\n", isEmptyQueue(q));
    printf("len: %d\n", lenQueue(q));
    clearQueue(&q);
    printf("test0");
    return 0;
}