#include "hash.c"

int main(){
    hashTable h;
    initHT(&h, 10);
    insertKey(&h, 5);
    insertKey(&h, 25);
    insertKey(&h, 15);
    insertKey(&h, 35);
    insertKey(&h, 95);
    // insertKey(&h, 29);

    printf("Key found at: %d\n", searchKey(h, 35));
    printf("Key found at: %d\n", searchKey(h, 15));
    printf("Key found at: %d\n", searchKey(h, 2));

    for(int i = 0; i < h.size; i++){
        printf("%d ", h.ht[i]);
    }
    printf("\n");

    deleteHashTable(&h);
    return 0;
}