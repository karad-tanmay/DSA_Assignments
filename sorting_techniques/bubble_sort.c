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

int main(){
    int arr[10] = {1, 2, 9, 5, 6, 4, 0, -1, 2, 1};
    display_arr(arr, 10);
    bubble_sort(arr, 10);
    display_arr(arr, 10);
    return 0;
}