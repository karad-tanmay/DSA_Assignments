#include <stdio.h>
#define SIZE 50

int linear_search(int *arr, int len, int key){
    for(int i = 0; i < len; i++){
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int main(){
    int arr[SIZE] = {8, 77, 39, 61, 30, 31, 94, 3, 95, 17, 27, 88, 15, 61, 68, 12, 19, 33, 62, 100, 37, 56, 90, 38, 92, 29, 49, 79, 35, 56, 12, 14, 6, 74, 77, 86, 62, 71, 98, 25, 22, 27, 65, 29, 83, 74, 89, 62, 94, 48};
    int user_ip;
    scanf("%d", &user_ip);
    int temp = linear_search(arr, SIZE, user_ip);
    if(temp == -1)
        printf("Not Found.");
    else
        printf("Number found at index: %d.", temp);
    return 0;
}