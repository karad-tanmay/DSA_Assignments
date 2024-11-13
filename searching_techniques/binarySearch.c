#include <stdio.h>

int binarySearch(int *arr, int lb, int ub, int key){
    if(lb > ub)
        return -1;
    int mid = (lb + ub) / 2;
    if(key == arr[mid])
        return mid;
    else if(key < arr[mid])
        return binarySearch(arr, lb, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, ub, key);
}