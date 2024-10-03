#include <stdio.h>
#include "queue.h"

int main(){
    queue q;
    init(&q, 5);
    for(int i = 0; i < 6; i++)
        enqueue(&q, i + 1);
    dequeue(&q);
    enqueue(&q, 6);
    displayQueue(q);
    printf("PeekFront: %d\n", peekFront(q));
    printf("PeekRear: %d\n", peekRear(q));
    for(int i = 0; i < 6; i++)
        printf("dequeue: %d\n", dequeue(&q));
    clearQueue(&q);
    printf("test0\n");
    return 0;
}