#include <stdio.h>
#define SIZE 10

int get_2ndmax(int *arr, int len){
    int max_a = arr[0];
    int max_b = arr[0];
    for(int i = 0; i < len; i++){
        if(arr[i] > max_a){
            max_b = max_a;
            max_a = arr[i];
        }
        else if(max_b < arr[i])
            max_b = arr[i];
    }
    return max_b;
}

int main(){
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("2nd Max: %d", get_2ndmax(arr, SIZE));
    return 0;
}