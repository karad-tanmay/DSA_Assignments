#include <stdio.h>

int main(){
    int m, n;
    printf("Enter the value of m and n (m < n): ");
    scanf("%d%d", &m, &n);
    printf("Odd numbers between %d and %d:\n", m, n);
    for(int i = m; i <= n; i++){
        if(i % 2 != 0)
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}