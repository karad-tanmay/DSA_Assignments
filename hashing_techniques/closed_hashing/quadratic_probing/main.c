// #include "hash.c"

// int main(){
//     hashTable h;
//     initHT(&h, 10);
//     insertKey(&h, 10);
//     insertKey(&h, 25);
//     insertKey(&h, 15);
//     insertKey(&h, 35);
//     insertKey(&h, 6);
//     insertKey(&h, 29);

//     printf("Key found at: %d\n", searchKey(h, 29));
//     printf("Key found at: %d\n", searchKey(h, 6));
//     printf("Key found at: %d\n", searchKey(h, 2));

//     for(int i = 0; i < h.size; i++){
//         printf("%d ", h.ht[i]);
//     }
//     printf("\n");

//     deleteHashTable(&h);
//     return 0;
// }


#include "hash.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

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

int read_file(int fd, char *filename, hashTable *h){
    fd = open(filename, O_RDONLY);
    if(fd == -1){
        perror("Open Failed!");
        return errno;
    }
    char word[12];
    read_line(fd, word);
    int n = atoi(word);
    if(n <= 0)
        return -1;
    int i = n, temp;
    while(i){
        read_line(fd, word);
        temp = atoi(word);
        insertKey(h, temp);
        i--;
    }
    return n;
}

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("No Input file.\n");
        return -1;
    }

    hashTable h;
    initHT(&h, 13);

    int fd = 0;
    int n = read_file(fd, argv[1], &h);
    if(n == -1)
        return 0;

    printf("HashMap: \n");

    for(int i = 0; i < h.size; i++)
        printf("Index %d: %d\n", i, h.ht[i]);
        
    deleteHashTable(&h);
    printf("test0");
    return 0;
}