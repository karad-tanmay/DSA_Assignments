#include "hash.c"

int main(){
    hashTable h;
    initHT(&h, 10);
    // printf("test1\n");
    insertKey(&h, 25);
    // printf("test2\n");
    insertKey(&h, 2);
    insertKey(&h, 450);
    insertKey(&h, 0);
    insertKey(&h, 30);
    insertKey(&h, -10);
    insertKey(&h, 19);
    insertKey(&h, 7);
    insertKey(&h, 108);
    insertKey(&h, 66);
    insertKey(&h, 31);
    insertKey(&h, 93);
    insertKey(&h, 124);
    // printf("test3\n");

    printf("Key found at: %d\n", searchKey(h, 20));
    printf("Key found at: %d\n", searchKey(h, 450));
    printf("Key found at: %d\n", searchKey(h, 108));
    printf("Key found at: %d\n", searchKey(h, -10));

    removeKey(&h, 108);
    removeKey(&h, 31);

    for(int i = 0; i < h.size; i++)
        display(h.ht[i]);
        
    deleteHashTable(&h);
    printf("test0");
    return 0;
}