#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "maxHeap.h"

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void init(maxHeap *h, int size){
    if(size <= 0)
        return;
    h->size = size;
    h->arr = (int*)malloc(sizeof(int) * size);
    h->rear = -1;
    for(int i = 0; i < size; i++)
        h->arr[i] = INT_MIN;
    return;
}

int getParentIndex(int i){
    if(i == 0)
        return 0;
    if(i % 2 == 1)
        return (i - 1) / 2;
    else
        return (i - 2) / 2;
}

void insert(maxHeap *h, int data){
    if(h->rear >= h->size - 1)
        return;
    h->rear++;
    h->arr[h->rear] = data;
    int i = h->rear, j;
    while(i > 0){
        j = getParentIndex(i);
        if(h->arr[i] > h->arr[j]){
            swap(&h->arr[i], &h->arr[j]);
            i = j;
        }
        else
            break;
    }
    return;
}

int remove_ele(maxHeap *h){
    if(h->rear == -1)
        return INT_MIN;
    int temp = h->arr[0];
    h->arr[0] = h->arr[h->rear];
    h->rear--;
    int i = 0, j = 0, k = 0, max_index = i;
    while(j <= h->rear && k <= h->rear){
        j = (2*i) + 1;
        k = (2*i) + 2;
        if(h->arr[j] > h->arr[max_index])
            max_index = j;
        if(h->arr[k] > h->arr[max_index])
            max_index = k;
        if(max_index != i){
            swap(&h->arr[i], &h->arr[max_index]);
            i = max_index;
        }
        else
            return temp;
    }
    return temp;
}

// needs to be checked
void heapSort(maxHeap *h){
    if(h->rear == -1)
        return;
    int temp, j = 0, k = 0, l = 0, max_index;
    for(int i = h->rear; i >= 0; i--){
        // printf("test1, i: %d\n", i);
        temp = h->arr[0];
        h->arr[0] = h->arr[i];
        l = j = k = max_index = 0;
        while(j < i && k < i){
            j = (2*l) + 1;
            k = (2*l) + 2;
            // printf("test2, j: %d, k: %d\n", j, k);
            if(j >= i || k >= i)
                break;
            if(h->arr[j] > h->arr[max_index])
                max_index = j;
            if(h->arr[k] > h->arr[max_index])
                max_index = k;
            if(max_index != i){
                swap(&h->arr[l], &h->arr[max_index]);
                l = max_index;
            }
            else
                break;
        }
        h->arr[i] = temp;
        // displayArray(*h);
    }
    return;
}

void deleteHeap(maxHeap *h){
    free(h->arr);
    h->arr = NULL;
    h->size = 0;
    h->rear = -1;
    return;
}

void displayArray(maxHeap h){
    for(int i = 0; i <= h.rear; i++)
        printf("%d ", h.arr[i]);
    printf("\n");
}

// void heapify(int *arr, int size, int i){
//     int j, k, max_index = i;
//     j = (2*i) + 1;
//     k = (2*i) + 2;
//     if(j < size && arr[j] > arr[max_index])
//         max_index = j;
//     if(k < size && arr[k] > arr[max_index])
//         max_index = k;
//     if(max_index != i){
//         swap(&arr[i], &arr[max_index]);
//         heapify(arr, size, max_index);
//     }
//     return;
// }

// void heap_sort(int *arr, int size){
//     // creating max heap
//     for(int i = size / 2 - 1; i >= 0; i--)
//         heapify(arr, size, i);
    
//     // heap sort
//     for(int i = size - 1; i > 0; i--){
//         swap(&arr[0], &arr[i]);
//         heapify(arr, i, 0);
//     }
//     return;
// }