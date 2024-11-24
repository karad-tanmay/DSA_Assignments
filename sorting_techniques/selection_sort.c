#include <stdio.h>
#include <stdlib.h>

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

// selection sort
void selec_sort(int *arr, int len)
{
    int i, j, min_index;
    for (i = 0; i < len - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        swap(&arr[i], &arr[min_index]);
    }
    return;
}

int main()
{
    int arr[10] = {1, 2, 9, 5, 6, 4, 0, -1, 2, 1};
    display_arr(arr, 10);
    selec_sort(arr, 10);
    display_arr(arr, 10);
    return 0;
}