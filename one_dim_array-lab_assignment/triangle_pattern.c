#include <stdio.h>
#define SIZE 10

void display_in_pattern(int *arr, int len){
    int i, j;
    for(i = 0; i < len; i++){
        for(j = 0; j <= i; j++)
            printf("%d ", arr[j]);
        printf("\n");
    }
    return;
}

int main(){
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display_in_pattern(arr, SIZE);
    return 0;
}