#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[10];
    int c;
    for (c = 0; c < 10; c++)
        arr[c] = rand() % 51 + 50;
    printf("Random numbers in the range [50, 100]:\n");
    for (c = 0; c < 10; c++)
        printf("%d ", arr[c]);
    return 0;
}