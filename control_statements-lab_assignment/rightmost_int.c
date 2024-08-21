#include <stdio.h>

int main() {
    float num;
    int int_part, temp;
    printf("Enter a floating-point number (< 10000 and > -10000): ");
    scanf("%f", &num);
    int_part = (int)num;
    temp = int_part % 10;
    printf("Rightmost digit of the integral part: %d\n", temp);
    return 0;
}