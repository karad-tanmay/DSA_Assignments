#include <stdio.h>
#define SIZE 10

void display_reverse(int *arr, int len){
    for(int i = len - 1; i >= 0; i--)
        printf("%d ", arr[i]);
    return;
}

int main(){
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display_reverse(arr, SIZE);
    return 0;
}