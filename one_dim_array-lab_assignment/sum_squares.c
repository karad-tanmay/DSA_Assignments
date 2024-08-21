#include <stdio.h>
#define SIZE 10

int sum_squares(int *arr, int len){
    int sum = 0, sq = 1;
    for(int i = 0; i < len; i++){
        sq = arr[i];
        sq *= arr[i];
        sum += sq;
    }
    return sum;
}

int main(){
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Sum of Squares = %d.", sum_squares(arr, SIZE));
    return 0;
}