#include "hash.c"

int main(){
    hashTable h;
    initHT(&h, 10);
    insertKey(&h, 10);
    insertKey(&h, 25);
    insertKey(&h, 15);
    insertKey(&h, 35);
    insertKey(&h, 6);
    insertKey(&h, 29);

    printf("Key found at: %d\n", searchKey(h, 29));
    printf("Key found at: %d\n", searchKey(h, 6));
    printf("Key found at: %d\n", searchKey(h, 2));

    for(int i = 0; i < h.size; i++){
        printf("%d ", h.ht[i]);
    }
    printf("\n");

    deleteHashTable(&h);
    return 0;
}