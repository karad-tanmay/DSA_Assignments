#include <stdio.h>
#include <stdlib.h>

// int len(int *arr){
//     int i = *(arr + 1) - *arr;
//     // for(i = 0; arr[i] != '\0'; i++);
//     // i++;
//     return i;
// }

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void display_arr(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return;
}

void merge(int *arr, int low, int mid, int high)
{
    int temp[100];
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= high)
        temp[k++] = arr[j++];
    for (i = low, j = 0; i <= high; i++)
        arr[i] = temp[j++];
    return;
}

void mS(int *arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mS(arr, low, mid);
    mS(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

// merge sort
void merge_sort(int *arr, int len)
{
    mS(arr, 0, len - 1);
    return;
}

int main()
{
    int arr[10] = {1, 2, 9, 5, 6, 0, 4, -1, 2, 1};
    display_arr(arr, 10);
    merge_sort(arr, 10);
    display_arr(arr, 10);
    // printf("len: %d\n", len(arr));
    return 0;
}