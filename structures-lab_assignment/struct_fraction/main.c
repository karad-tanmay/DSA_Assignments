#include <stdio.h>
#include "fraction.h"

int main(){
    fraction a;
    fraction b;
    int num, denom;

    printf("Fraction 1:");
    printf("Enter numerator and denominator: ");
    scanf("%d %d", &num, &denom);
    init(&a, num, denom);

    printf("Fraction 2:");
    printf("Enter numerator and denominator: ");
    scanf("%d %d", &num, &denom);
    init(&b, num, denom);

    display(a);
    display(b);

    printf("%d", cmp_fraction(a, b));

    return 0;
}