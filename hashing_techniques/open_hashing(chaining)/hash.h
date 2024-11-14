#include "../../singly_linked_list-lab_assignment_adt/int_sll/sll.c"

typedef struct hashTable{
    int size;
    list* ht;
}hashTable;

void initHT(hashTable *h, int size);
int hash(int key, int size);
void insertKey(hashTable *h, int key);
int searchKey(hashTable h, int key);
void removeKey(hashTable *h, int key);
void deleteHashTable(hashTable *h);