#include <stdio.h>

int main(){
    float num1, num2;
    int sum;
    printf("Enter the first floating-point number: ");
    scanf("%f", &num1);
    printf("Enter the second floating-point number: ");
    scanf("%f", &num2);
    sum = (int)(num1 + num2);
    printf("First number: %f\n", num1);
    printf("Second number: %f\n", num2);
    printf("Sum as integer: %d\n", sum);
    return 0;
}
