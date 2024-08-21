#include <stdio.h>
#include <stdbool.h>

int is_prime(int num) {
    if(num <= 1)
        return 0;
    for(int i = 2; i <= num / 2; i++){
        if(num % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int m, n;
    printf("Enter the value of m and n (m < n): ");
    scanf("%d%d", &m, &n);
    printf("Prime numbers between %d and %d:\n", m, n);
    for(int i = m; i <= n; i++){
        if(is_prime(i))
            printf("%d ", i);
    }
    return 0;
}
