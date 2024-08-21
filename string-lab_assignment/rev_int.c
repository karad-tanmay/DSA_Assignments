#include <stdio.h>

int rev_int(int num){
    if(num == 0)
        return 0;
    int arr[12];
    int i, num_digits = 0, temp = 0;
    for(i = 0; num != 0; i++){
        arr[i] = num % 10;
        num_digits++;
        num /= 10;
    }
    for(i = 0; i < num_digits - 1; i++){
        temp += arr[i];
        temp *= 10;
    }
    temp += arr[i];
    return temp;
}

int main(){
    int num, rev_num;
    scanf("%d", &num);
    rev_num = rev_int(num);
    printf("%d", rev_num);
    return 0;
}