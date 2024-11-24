#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <time.h>
#include "sorting_tech.c"

int read_line(int fd, char *word)
{
    char ch;
    int i = 0;
    while (read(fd, &ch, 1))
    {
        if (ch == '\n')
            break;
        word[i++] = ch;
    }
    word[i] = '\0';
    return i;
}

int *read_file(int fd, char *filename, int *len)
{
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Open Failed!");
        return NULL;
    }
    char word[12];
    read_line(fd, word);
    int n = atoi(word);
    if (n <= 0)
        return NULL;
    int i = 0, temp;
    int *arr = (int *)malloc(n * sizeof(int));
    while (i < n)
    {
        read_line(fd, word);
        temp = atoi(word);
        arr[i++] = temp;
    }
    *len = n;
    return arr;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("No Input file.\n");
        return -1;
    }
    int fd = 0;
    int n;
    int *arr1 = read_file(fd, argv[1], &n);
    if (arr1 == NULL)
        return 0;
    // printf("test0\n");
    // creating 3 copies of dataset (array).
    int *arr2 = (int *)malloc(n * sizeof(int));
    int *arr3 = (int *)malloc(n * sizeof(int));
    int *arr4 = (int *)malloc(n * sizeof(int));
    int *arr5 = (int *)malloc(n * sizeof(int));

    memcpy(arr2, arr1, n * sizeof(int));
    memcpy(arr3, arr1, n * sizeof(int));
    memcpy(arr4, arr1, n * sizeof(int));
    memcpy(arr5, arr1, n * sizeof(int));

    // printf("test1\n");

    // clock cycle var -
    clock_t t_start, t_end;

    // bubble sort -
    t_start = clock();
    bubble_sort(arr1, n);
    t_end = clock();
    printf("Time taken by Bubble Sort: %.3lf s\n", (double)(t_end - t_start) / CLOCKS_PER_SEC);
    // display_arr(arr1, n);

    // insertion sort -
    t_start = clock();
    insertion_sort(arr2, n);
    t_end = clock();
    printf("Time taken by Insertion Sort: %.3lf s\n", (double)(t_end - t_start) / CLOCKS_PER_SEC);
    // display_arr(arr2, n);

    // selection sort -
    t_start = clock();
    selec_sort(arr3, n);
    t_end = clock();
    printf("Time taken by Selection Sort: %.3lf s\n", (double)(t_end - t_start) / CLOCKS_PER_SEC);
    // display_arr(arr3, n);

    // heap sort -
    t_start = clock();
    heap_sort(arr5, n);
    t_end = clock();
    printf("Time taken by Heap Sort: %.3lf s\n", (double)(t_end - t_start) / CLOCKS_PER_SEC);
    // display_arr(arr5, n);

    // quick sort -
    t_start = clock();
    quickSort(arr4, n);
    t_end = clock();
    printf("Time taken by Quick Sort: %.3lf s\n", (double)(t_end - t_start) / CLOCKS_PER_SEC);
    // display_arr(arr4, n);

    free(arr1);
    free(arr2);
    free(arr3);
    free(arr4);
    free(arr5);
    // printf("test2\n");
    return 0;
}