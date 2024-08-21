#include <stdio.h>

int main(){
    int deci, temp;
    int bin[32] = {0};
    scanf("%d", &deci);
    temp = deci;
    if(deci < 0)
        deci *= -1;
    for(int i = 0; deci != 0; i++){
        bin[i] = deci % 2;
        deci /= 2;
    }

    if(temp < 0){  // take 2's complement if no. is negative.
        deci = temp * -1;
        for(int i = 31; i >= 0; i--)
            bin[i] = bin[i] ^ 1;
        if(deci % 2 == 1)
            bin[0] = 1;
        else{
            bin[0] = 0;
            temp = 1;
            for(int i = 1; temp != 0; i++){
                if(bin[i] == 0){
                    bin[i] = 1;
                    temp = 0;
                }
                else
                    bin[i] = 0;
            } 

        }
    }

    for(int i = 31; i >= 0; i--)
        printf("%d", bin[i]);
    return 0;
}