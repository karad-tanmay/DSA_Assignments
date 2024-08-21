#include <stdio.h>

int main(){
    int nums[10];
    for(int i = 0; i < 10; i++){
        printf("Enter number: ");
        scanf("%d", &nums[i]);
    }
    for(int i = 0; i < 10; i++){
        printf("%d", nums[i]);
        if((i + 1) % 3 == 0 || i == 9)
            printf("\n");
        else
            printf(", ");
    }
    return 0;
}