#include <stdio.h>
#define SIZE 10

void swap(int *a, int *b){
    int tp = *a;
    *a = *b;
    *b = tp;
    return;
}

void reverse(int *arr, int len){
    int i, j;
    for(i = 0, j = len - 1; i < j; i++, j--)
        swap(&arr[i], &arr[j]);
}

int main(){
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    reverse(arr, SIZE);
    for(int i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);
    return 0;
}