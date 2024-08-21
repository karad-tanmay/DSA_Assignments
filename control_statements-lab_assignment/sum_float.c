#include <stdio.h>

int main(){
    float num1, num2, num3, result;
    printf("Enter three floating-point numbers:\n");
    scanf("%f %f %f", &num1, &num2, &num3);
    result = num1 + num2 + num3;
    printf("Result: %.2f\n", result);
    return 0;
}
