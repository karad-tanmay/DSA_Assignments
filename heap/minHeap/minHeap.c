#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "minHeap.h"

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

void initHeap(minHeap *h, int size){
	if(size <= 0)
		return;
	h->arr = (int*)calloc(size, sizeof(int));
	if(h->arr == NULL)
		return;
	h->size = size;
	h->rear = 0;
	return;
}

int getParent(int i){
	if(i == 0)
		return -1;
	else if(i % 2 == 1)
		return (i - 1) / 2;
	else
		return (i - 2) / 2;
}

void insert(minHeap *h, int data){
	if(h->rear >= h->size)
		return;
	h->arr[h->rear++] = data;
	int i = h->rear - 1, j = getParent(i);
	while(i > 0 && j >= 0 && h->arr[i] < h->arr[j]){
		swap(&h->arr[i], &h->arr[j]);
		i = j;
		j = getParent(i);
	}
	return;
}

int removeEle(minHeap *h){
	if(h->rear == 0)
		return INT_MIN;
	if(h->rear == 1){
		h->rear--;
		return h->arr[h->rear];
	}
	swap(&h->arr[0], &h->arr[h->rear - 1]);
	h->rear--;
	int i = 0, j = 0, k = 0, min_index = 0;
	j = (2*i) + 1;
	k = (2*i) + 2;
	while(j < h->rear && k < h->rear){
		if(h->arr[min_index] > h->arr[j])
			min_index = j;
		if(h->arr[min_index] > h->arr[k])
			min_index = k;
		if(min_index == i)
			break;
		else
			swap(&h->arr[i], &h->arr[min_index]);
		i = min_index;
		j = (2*i) + 1;
		k = (2*i) + 2;
	}
	return h->arr[h->rear];
}

void heapify(minHeap *h, int i, int size){
	if(h->size == 0)
		return;
	if(i < 0 || i >= h->size)
		return;
	int j = (2*i) + 1;
	int k = (2*i) + 2;
	int min_index = i;
	if(j < size && h->arr[min_index] > h->arr[j])
		min_index = j;
	if(k < size && h->arr[min_index] > h->arr[k])
		min_index = k;
	if(min_index != i){
		swap(&h->arr[i], &h->arr[min_index]);
		heapify(h, min_index, size);
	}
	return;
}

void heapSort(minHeap *h){ //considering a heap is already provided;
	for(int i = h->rear - 1; i > 0; i--){
		swap(&h->arr[0], &h->arr[i]);
		heapify(h, 0, i);
	}
	return;
}

void deleteHeap(minHeap *h){
	free(h->arr);
	h->arr = NULL;
	h->rear = h->size = 0;
	return;
}

void displayHeap(minHeap h){
	if(h.rear == 0)
		return;
	for(int i = 0; i < h.rear; i++)
		printf("%d ", h.arr[i]);
	return;
}
