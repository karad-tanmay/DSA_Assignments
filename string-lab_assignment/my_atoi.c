#include <stdio.h>
#include <limits.h>
#include <string.h>
#define NUM_SIZE 512

/* Flags used-
    sf - sign flag
        sf = 0 -> no sign set / encountered
        sf = 1 -> +ve sign
        sf = -1 -> -ve sign

    wf - whitespace flag
        wf = 1 -> ignore whitespace (since they are leading whitespaces)
        wf = 0 -> don't ignore white space (since they are in between digits)

    zf - zero flag
        zf = 0 -> ignore zeros (since they are leading)
        zf = 1 -> dont ignore zeros (since they are between nos.)
*/

void display(int *arr, int i){
    for(int j = 0; j < i; j++){
        printf("%d ", arr[j]);
    }
    printf("\n");
}

int valid_char(char a){
    int temp = (int)a;
    if(temp != 32 && temp != 43 && temp != 45 && (temp < 48 || temp > 57))
        return 0;
    return 1;
}

int get_digit(char a){
    int temp = (int)a;
    return temp - 48;
}

int myAtoi(char* s) {
    int sf = 0, wf = 1, i = 0, zf = 0, j = 0;
    long sum = 0, tp = 1;
    int arr[NUM_SIZE];
    // printf("test1\n");
    while(s[i] != '\0'){
        // printf("test2\n");
        if(!(valid_char(s[i]))){
            // printf("test3\n");
            break;
        }
        else if(s[i] == ' ' && wf == 1){
            i++;
            // printf("test4\n");
            // continue;
        }
        else if(s[i] == ' ' && wf == 0){
            // printf("test5\n");
            break;
        }
        else if(s[i] == '+' && sf == 0){
            sf = 1;
            wf = 0;
            i++;
            // printf("test6\n");
            // continue;
        }
        else if(s[i] == '-' && sf == 0){
            sf = -1;
            wf = 0;
            i++;
            // printf("test7\n");
            // continue;
        }
        else if((s[i] == '+' || s[i] == '-') && sf != 0){
            // printf("test8\n");
            break;
        }
        else if(s[i] == '0' && zf == 0){
            wf = 0;
            if(sf == 0)
                sf = 1;
            i++;
            // printf("test9\n");
            // continue;
        }
        else if(s[i] >= '0' && s[i] <= '9'){
            wf = 0;
            if(sf == 0)
                sf = 1;
            zf = 1;
            arr[j++] = get_digit(s[i]);
            i++;
            // printf("test10\n");
        }
        // display(arr, j);
    }
    // printf("j: %d\n", j);

    j--;
    if(j >= 10){
        if(sf == 1)
            return INT_MAX;
        else
            return INT_MIN;
    }

    else if(j < 0)
        return 0;

    // printf("j: %d\n", j);
    for(; j >= 0; j--){
        sum += arr[j] * tp;
        tp *= 10;
    }

    if(sf == -1)
        sum *= -1;

    // printf("SUM: %d\n", sum);

    if(sum >= INT_MIN && sum <= INT_MAX)
        return (int)sum;
    else if(sum < INT_MIN)
        return INT_MIN;
    else
        return INT_MAX;
}

int main(){
    int temp = myAtoi("2147483646");
    printf("%d\n", temp);
    // printf("test0\n");
    return 0;
}