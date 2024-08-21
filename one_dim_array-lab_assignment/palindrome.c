#include <stdio.h>
#define SIZE 10

int palindrome(int *arr, int len){
    int i, j;
    for(i = 0, j = len - 1; i < j; i++, j--){
        if(arr[i] != arr[j])
            return -1;
    }
    return 0;
}

int main(){
    int arr[SIZE] = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};
    int tp = palindrome(arr, SIZE);
    if(tp == 0)
        printf("Is Palindrome.");
    else
        printf("Is Not Palindrome.");
    return 0;
}