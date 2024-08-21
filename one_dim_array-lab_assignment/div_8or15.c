#include <stdio.h>
#define SIZE 100

void display(int *arr, int len){
    for(int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int div_by_8(int *arr, int len, int *div){
    int k = 0;
    for(int i = 0; i < len; i++){
        if(arr[i] % 8 == 0)
            div[k++] = arr[i];
    }
    return k;
}

int div_by_15(int *arr, int len, int *div){
    int k = 0;
    for(int i = 0; i < len; i++){
        if(arr[i] % 15 == 0)
            div[k++] = arr[i];
    }
    return k;
}

int main(){
    int arr[SIZE] = {408, 126, 639, 185, 108, 49, 62, 137, 197, 520, 9, 609, 953, 217, 266, 716, 239, 194, 649, 227, 899, 641, 381, 931, 829, 445, 702, 527, 490, 528, 966, 363, 634, 753, 312, 606, 763, 567, 315, 495, 964, 645, 179, 495, 346, 785, 854, 628, 768, 871, 703, 101, 356, 447, 344, 863, 326, 80, 53, 279, 275, 864, 365, 984, 521, 318, 368, 961, 105, 280, 363, 341, 31, 51, 952, 751, 134, 963, 676, 920, 865, 549, 765, 370, 879, 103, 897, 62, 45, 536, 871, 529, 169, 542, 972, 669, 974, 288, 630, 477};
    int div_8[SIZE], div_15[SIZE];
    int len_8 = div_by_8(arr, SIZE, div_8);
    int len_15 = div_by_15(arr, SIZE, div_15);
    display(div_8, len_8);
    display(div_15, len_15);
    return 0;
}