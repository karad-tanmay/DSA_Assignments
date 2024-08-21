#include <stdio.h>
#define SIZE 10

void rotate_n_left(int *arr, int len, int n){
    int temp;
    int i, j;
    for(i = 0; i < n; i++){
        temp = arr[0];
        for(j = 0; j < len - 1; j++)
            arr[j] = arr[j + 1];
        arr[len - 1] = temp;
    }
    return;
}

void rotate_n_right(int *arr, int len, int n){
    int temp;
    int i, j;
    for(i = 0; i < n; i++){
        temp = arr[len - 1];
        for(j = len - 1; j > 0; j--)
            arr[j] = arr[j - 1];
        arr[0] = temp;
    }
    return;
}

int main(){
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n, dir;
    printf("Give number of positions to rotate by and direction of rotation (left:1, right:2): ");
    scanf("%d%d", &n, &dir);
    if(dir == 1)
        rotate_n_left(arr, SIZE, n);
    else if(dir == 2)
        rotate_n_right(arr, SIZE, n);
    for(int i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);
    return 0;
}