typedef struct hashTable{
    int size;
    int *ht;
}hashTable;

void initHT(hashTable *h, int size);
int hash(int key, int size);
int probe(hashTable h, int key);
void insertKey(hashTable *h, int key);
int searchKey(hashTable h, int key);
// void removeKey(hashTable *h, int key); to be skipped
void deleteHashTable(hashTable *h);