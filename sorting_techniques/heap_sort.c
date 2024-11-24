#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void heapify(int *arr, int size, int i)
{
    int j, k, max_index = i;
    j = (2 * i) + 1;
    k = (2 * i) + 2;
    if (j < size && arr[j] > arr[max_index])
        max_index = j;
    if (k < size && arr[k] > arr[max_index])
        max_index = k;
    if (max_index != i)
    {
        swap(&arr[i], &arr[max_index]);
        heapify(arr, size, max_index);
    }
    return;
}

void heap_sort(int *arr, int size)
{
    // creating max heap
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    // heap sort
    for (int i = size - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
    return;
}

int main()
{
    int arr[7] = {5, 10, 30, 20, 35, 40, 15};
    int size = 7;
    heap_sort(arr, size);
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}