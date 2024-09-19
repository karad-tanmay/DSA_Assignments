#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void display_arr(int *arr, int len){
    for(int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
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

int main(){
    int arr[10] = {1, 2, 9, 5, 6, 4, 0, -1, 2, 1};
    display_arr(arr, 10);
    insertion_sort(arr, 10);
    display_arr(arr, 10);
    return 0;
}