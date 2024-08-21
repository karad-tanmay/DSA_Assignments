#include <stdio.h>
#include <limits.h>
#define MAX(a,b) ((a > b) ? (a) : (b))
#define MIN(a,b) ((a < b) ? (a) : (b))
#define SIZE 10

void nearest_greater_lesser(int *arr, int len, int *g, int *l, int key){
    for(int i = 0; i < len; i++){
        if(arr[i] > key)
            *g = MIN(arr[i], *g);
        else if(arr[i] < key)
            *l = MAX(arr[i], *l);
    }
}

int main(){
    int greater = INT_MAX, lesser = INT_MIN;
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key;
    scanf("%d", &key);
    nearest_greater_lesser(arr, SIZE, &greater, &lesser, key);
    printf("nearest lesser: %d\nnearest greatest: %d", lesser, greater);
    return 0;
}