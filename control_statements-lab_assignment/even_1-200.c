#include <stdio.h>

int main(){
    int count = 0, sum = 0;
    for(int i = 1; i < 200; i++){
        if(i % 2 == 0){
            count++;
            sum += i;
        }
    }
    printf("Count of even numbers between 1-200: %d\n", count);
    printf("Sum of even numbers between 1-200: %d\n", sum);
    return 0;
}