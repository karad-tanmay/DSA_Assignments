#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num % 5 == 0 && num % 11 == 0)
        printf("Number is divisible by 5 and 11\n");
    else
        printf("Number is not divisible by 5 and 11\n");

    return 0;
}
