#include <stdio.h>

int main(){
    float p, r, t, si, ci;
    float amt = 1.0;
    printf("Enter principal amt: ");
    scanf("%f", &p);
    printf("Enter interest rate: ");
    scanf("%f", &r);
    printf("Enter time (years): ");
    scanf("%f", &t);
    si = (p * r * t) / 100;
    float base = 1 + (r / 100);
    for(int i = 0; i < (int)t; i++)
        amt *= base;
    ci = (p * amt) - p;
    printf("Simple Interest: %.2f\n", si);
    printf("Compound Interest: %.2f\n", ci);
    return 0;
}