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

int getParentIndex(maxHeap h, int i){
    if(i == 0)
        return 0;
    if(i % 2 == 1)
        return (i - 1) / 2;
    else
        return (i - 2) / 2;
}

void insert(maxHeap *h, int data){
    if(h->rear >= h->size)
        return;
    h->rear++;
    h->arr[h->rear] = data;
    int i = h->rear, j;
    while(i > 0){
        j = getParentIndex(*h, i);
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
    int temp;
    temp = h->arr[0];
    h->arr[0] = h->arr[h->rear];
    h->rear--;
    int i = 0, j = 0, k = 0;
    while(j <= h->rear && k <= h->rear){
        j = (2*i) + 1;
        k = (2*i) + 2;
        if(h->arr[j] > h->arr[k]){
            if(h->arr[i] < h->arr[j]){
                swap(&h->arr[i], &h->arr[j]);
                i = j;
            }
            else
                return temp;
        }
        else{
            if(h->arr[i] < h->arr[k]){
                swap(&h->arr[i], &h->arr[k]);
                i = k;
            }
            else
                return temp;
        }
    }
    return temp;
}

void deleteHeap(maxHeap *h){
    free(h->arr);
    h->arr = NULL;
    h->size = 0;
    h->rear = -1;
    return;
}