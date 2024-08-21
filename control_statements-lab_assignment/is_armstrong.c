#include <stdio.h>
#include <math.h>

int is_armstrong(int num){
    int temp = num, sum = 0, digits = 0;
    while(num > 0) {
        num /= 10;
        digits++;
    }
    num = temp;
    while(num > 0) {
        int digit = num % 10;
        sum += pow(digit, digits);
        num /= 10;
    }
    return sum == temp;
}

int main(){
    int num;
    while(1){
        printf("Enter a number (-1 to stop): ");
        scanf("%d", &num);
        if(num == -1)
            break;
        if(is_armstrong(num)) 
            printf("%d is an Armstrong number.\n", num);
        else
            printf("%d is not an Armstrong number.\n", num);
    }
    return 0;
}