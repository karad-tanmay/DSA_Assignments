#include <stdio.h>

int main(){
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    printf("Decimal: %d\n", num);
    printf("Octal: %o\n", num);
    printf("Hexadecimal: %X\n", num);
    return 0;
}