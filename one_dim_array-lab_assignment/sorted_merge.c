#include <stdio.h>

void sorted_merge(int *a, int *b, int *c){
    int i = 0, j = 0, k = 0;
    while(i < 5 && j < 5){
        if(a[i] < b[j])
            c[k++] = a[i++];
        else if(a[i] > b[j])
            c[k++] = b[j++];
        else{
            c[k++] = a[i++];
            j++;
        }
    }
    for(; i < 5; i++)
        c[k++] = a[i];
    for(; j < 5; j++)
        c[k++] = b[j];
    return;
}

int main(){
    int A[5] = {45, 50, 70, 85, 90};
    int B[5] = {30, 40, 60, 75, 80};
    int C[10] = {0};
    sorted_merge(A, B, C);
    for(int i = 0; i < 10; i++)
        printf("%d ", C[i]);
    return 0;
}