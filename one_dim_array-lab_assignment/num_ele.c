#include <stdio.h>

int main(){
    int arr[] = {50, 60, 70, 80, 90, 100};
    int num_elements = sizeof(arr) / sizeof(arr[0]);
    printf("The number of elements in the array is: %d\n", num_elements);
    return 0;
}
