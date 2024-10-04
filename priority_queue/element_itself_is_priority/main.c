#include <stdio.h>
#include "pqueue.h"

int main(){
    pqueue pq;
    init(&pq);
    enqueue(&pq, 10);
    enqueue(&pq, 15);
    enqueue(&pq, 5);
    enqueue(&pq, 0);
    enqueue(&pq, 25);
    printf("isEmpty: %d\n", isEmpty(pq));

    printf("len: %d\n", len(pq));

    displayQueue(pq);
    for(int i = 0; i < 6; i++)
        printf("dequeue: %d\n", dequeue(&pq));

    clearQueue(&pq);
    printf("len: %d\n", len(pq));
    printf("test0\n");
    return 0;
}