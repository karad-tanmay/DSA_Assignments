#include "hash.c"

int main(){
    hashTable h;
    init(&h, 10);
    insertKey(&h, 5);
    insertKey(&h, 9);
    insertKey(&h, 6);
    insertKey(&h, 8);
    insertKey(&h, 2);
    printf("Key found at: %d\n", searchKey(h, 2));
    printf("Key found at: %d\n", searchKey(h, 5));
    printf("Key found at: %d\n", searchKey(h, 1));
    printf("Key found at: %d\n", searchKey(h, 7));
    removeKey(&h, 2);
    removeKey(&h, 5);
    removeKey(&h, 8);
    printf("Key found at: %d\n", searchKey(h, 2));
    printf("Key found at: %d\n", searchKey(h, 5));
    deleteHashTable(&h);
    return 0;
}