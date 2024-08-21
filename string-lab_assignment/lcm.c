#include <stdio.h>
#include <limits.h>

int lcm(int a, int b){
    if(a > 0 && b > 0){
        int i;
        for(i = 1; i % a != 0 || i % b != 0; i++);
        return i;
    }
    return INT_MIN;
}

int main(){
    int a, b;
    printf("enter two ints: ");
    scanf("%d %d", &a, &b);
    printf("LCM of %d and %d is: %d", a, b, lcm(a, b));
    return 0;
}