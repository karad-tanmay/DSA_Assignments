#include <stdio.h>
#include <limits.h>
#define max(a, b) ((a > b) ? a : b)

int gcd(int a, int b){
    if(a > 0 && b > 0){
        int i;
        for(i = 2; (a % i != 0 || b % i != 0) && i <= a && i <= b; i++);
        if(i != max(a, b))
            return i;
    }
    return INT_MIN;
}

int main(){
    int a, b;
    printf("enter two ints: ");
    scanf("%d %d", &a, &b);
    printf("GCD of %d and %d is: %d", a, b, gcd(a, b));
    return 0;
}