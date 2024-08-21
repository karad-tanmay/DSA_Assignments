#include <stdio.h>

int main(){
    float num;
    printf("Enter a floating-point value: ");
    scanf("%f", &num);
    printf("Correct to two decimal places: %.2e\n", num);
    printf("Correct to four decimal places: %.4e\n", num);
    printf("Correct to eight decimal places: %.8e\n", num);
    return 0;
}