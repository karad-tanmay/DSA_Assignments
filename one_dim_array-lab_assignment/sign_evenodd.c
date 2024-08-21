#include <stdio.h>
#define SIZE 20

void get_count(int *arr, int len, int *even, int *odd, int *posi, int *neg, int *zero){
    for(int i = 0; i < len; i++){
        if(arr[i] > 0)
            *posi += 1;
        else if(arr[i] < 0)
            *neg += 1;
        else
            *zero += 1;
        if(arr[i] % 2 == 0)
            *even += 1;
        else
            *odd += 1;
    }
    return;
}

int main(){
    int arr[SIZE] = {55, 0, -84, 81, 96, -57, -76, -65, 21, 60, 0, 11, -20, 73, -56, 0, -27, -9, 100, -15};
    int even = 0, odd = 0, posi = 0, neg = 0, zero = 0;
    get_count(arr, SIZE, &even, &odd, &posi, &neg, &zero);
    printf("number of positive numbers: %d\nnumber of negative numbers: %d\nnumber of odd numbers: %d\nnumber of even numbers: %d\nnumber of 0: %d\n", posi, neg, odd, even, zero);
    return 0;
}