#include <stdio.h>
#define SIZE 10

void swap(int *a, int *b){
    int tp = *a;
    *a = *b;
    *b = tp;
    return;
}

int remove_dupl(int *arr, int len){
    int i, j;
    for(i = 0; i < len; i ++){
        for(j = i + 1; j < len; j++){
            if(arr[i] == arr[j]){
                swap(&arr[j], &arr[len - 1]);
                len--;
            }
        }
    }
    return len;
}

int main(){
    int arr[SIZE] = {1, 2, 2, 3, 4, 5, 2, 1, 3, 5};
    int new_len = remove_dupl(arr, SIZE);
    for(int i = 0; i < new_len; i++)
        printf("%d ", arr[i]);
    return 0;
}