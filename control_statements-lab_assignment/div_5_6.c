#include <stdio.h>

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    printf("Is %d divisible by 5 and 6? %s\n", num, ((num % 5 == 0) && (num % 6 == 0)) ? "true" : "false");
    printf("Is %d divisible by 5 or 6? %s\n", num, ((num % 5 == 0) || (num % 6 == 0)) ? "true" : "false");
    printf("Is %d divisible by 5 or 6, but not both? %s\n", num, ((num % 5 == 0) ^ (num % 6 == 0)) ? "true" : "false");
    return 0;
}
