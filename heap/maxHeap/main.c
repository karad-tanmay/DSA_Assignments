#include <stdio.h>
#include "maxHeap.c"

int main(){
    maxHeap h;
    init(&h, 15);
    insert(&h, 15);
    insert(&h, 12);
    insert(&h, 19);
    insert(&h, 69);
    insert(&h, 9);
    insert(&h, 2);
    insert(&h, 34);
    displayArray(h);

    // printf("rmv-ele: %d\n", remove_ele(&h));
    // displayArray(h);

    // printf("rmv-ele: %d\n", remove_ele(&h));
    // displayArray(h);
    
    // printf("rmv-ele: %d\n", remove_ele(&h));
    // displayArray(h);
    
    // printf("rmv-ele: %d\n", remove_ele(&h));
    // displayArray(h);

    heapSort(&h);
    displayArray(h);

    deleteHeap(&h);
    printf("test0");
    return 0;
}