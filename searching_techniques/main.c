#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <time.h>
#include "search_tech.c"

int read_line(int fd, char *word){
    char ch;
    int i = 0;
    while(read(fd, &ch, 1)){
        if(ch == '\n')
            break;
        word[i++] = ch;
    }
    word[i] = '\0';
    return i;
}

int* read_file(int fd, char *filename, int *len){
    fd = open(filename, O_RDONLY);
    if(fd == -1){
        perror("Open Failed!");
        return NULL;
    }
    char word[12];
    read_line(fd, word);
    int n = atoi(word);
    if(n <= 0)
        return NULL;
    int i = 0, temp;
    int *arr = (int*)malloc(n * sizeof(int));
    while(i < n){
        read_line(fd, word);
        temp = atoi(word);
        arr[i++] = temp;
    }
    *len = n;
    return arr;
}

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("No Input file.\n");
        return -1;
    }
    int fd = 0;
    int n;
    int *arr1 = read_file(fd, argv[1], &n);
    if(arr1 == NULL)
        return 0;
    int temp;

    // clock cycle var -
    clock_t t_start, t_end;

    // finding 1st number of list:
    printf("Finding 1st element of dataset:\n");
    // linear search:
    t_start = clock();
    temp = linearSearch(arr1, n, -2147480087);
    t_end = clock();
    // printf("%d\n", temp);
    printf("Time taken by Linear Search: %.3lf s\n", (double)(t_end - t_start)/ CLOCKS_PER_SEC);
    
    // binary search:
    t_start = clock();
    temp = binarySearch(arr1, 0, n, -2147480087);
    t_end = clock();
    // printf("%d\n", temp);
    printf("Time taken by Binary Search: %.3lf s\n", (double)(t_end - t_start)/ CLOCKS_PER_SEC);

    // finding middle number of list:
    printf("Finding middle element of dataset:\n");
    // linear search:
    t_start = clock();
    temp = linearSearch(arr1, n, 25730276);
    t_end = clock();
    // printf("%d\n", temp);
    printf("Time taken by Linear Search: %.3lf s\n", (double)(t_end - t_start)/ CLOCKS_PER_SEC);
    
    // binary search:
    t_start = clock();
    temp = binarySearch(arr1, 0, n, 25730276);
    t_end = clock();
    // printf("%d\n", temp);
    printf("Time taken by Binary Search: %.3lf s\n", (double)(t_end - t_start)/ CLOCKS_PER_SEC);

    // finding 1st number of list:
    printf("Finding element not present in list (INT_MAX):\n");
    // linear search:
    t_start = clock();
    temp = linearSearch(arr1, n, INT_MAX);
    t_end = clock();
    // printf("%d\n", temp);
    printf("Time taken by Linear Search: %.3lf s\n", (double)(t_end - t_start)/ CLOCKS_PER_SEC);
    
    // binary search:
    t_start = clock();
    temp = binarySearch(arr1, 0, n, INT_MAX);
    t_end = clock();
    // printf("%d\n", temp);
    printf("Time taken by Binary Search: %.3lf s\n", (double)(t_end - t_start)/ CLOCKS_PER_SEC);


    free(arr1);
    return 0;
}