#include <stdio.h>
#include <stdlib.h>
#include "sorting_tech.h"

// helper func -
void display_arr(int *arr, int len){
    for(int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}


// bubble sort
void bubble_sort(int *arr, int len){
    int i, j, is_sort = 1;
    for(i = len - 1; i > 0; i--){
        for(j = 0; j < i; j++){
            if(arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
                is_sort = 0;
            }
        }
        if(is_sort)
            return;
    }
    return;
}

// insertion sort
void insertion_sort(int *arr, int len){
    int i, j;
    for(i = 0; i < len; i++){
        j = i;
        while(j > 0 && arr[j - 1] > arr[j]){
            swap(&arr[j - 1], &arr[j]);
            j--;
        }
    }
    return;
}

// selection sort
void selec_sort(int *arr, int len){
    int i, j, min_index;
    for(i = 0; i < len - 1; i++){
        min_index = i;
        for(j = i + 1; j < len; j++){
            if(arr[j] < arr[min_index])
                min_index = j;
        }
        swap(&arr[i], &arr[min_index]);
    }
    return;
}

// quick sort
int partition(int *arr, int low, int high){
    int pivot = arr[low];
    int i = low, j = high;
    while(i < j){
        while(arr[i] <= pivot && i < high)
            i++;
        while(arr[j] > pivot && j > low)
            j--;
        if(i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void qs(int *arr, int low, int high){
    int pIndex;
    if(low < high){
        pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
    return;
}

void quickSort(int *arr, int len){
    qs(arr, 0, len - 1);
    return;
}

// merge sort
void merge(int *arr, int low, int mid, int high){
    int temp[100];
    int i = low, j = mid + 1, k = 0;
    while(i <= mid && j <= high){
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while(i <= mid)
        temp[k++] = arr[i++];
    while(j <= high)
        temp[k++] = arr[j++];
    for(i = low, j = 0; i <= high; i++)
        arr[i] = temp[j++];
    return;
}

void mS(int *arr, int low, int high){
    if(low >= high)
        return;
    int mid = (low + high) / 2;
    mS(arr, low, mid);
    mS(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void merge_sort(int *arr, int len){
    mS(arr, 0, len - 1);
    return;
}

// heap sort
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i){
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int *arr, int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
    return;
}