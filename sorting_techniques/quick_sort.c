#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i < high)
            i++;
        while (arr[j] > pivot && j > low)
            j--;
        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void qs(int *arr, int low, int high)
{
    int pIndex;
    if (low < high)
    {
        pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
    return;
}

void quickSort(int *arr, int len)
{
    qs(arr, 0, len - 1);
    return;
}

int main()
{
    int arr[10] = {12, 0, -3, 4, 9, 23, -69, 77, -9, 0};
    quickSort(arr, 10);
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    return 0;
}