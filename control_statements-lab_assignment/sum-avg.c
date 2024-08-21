#include <stdio.h>

int main(){
    int n, sum = 0;
    float average;
    printf("Enter any num: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) 
        sum += i;
    average = (float)sum / n;
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    return 0;
}
