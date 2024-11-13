typedef struct hashTable{
    int size;
    int *arr;
}hashTable;

void init(hashTable *h, int size);
int hash(int key);
void insertKey(hashTable *h, int key);
int searchKey(hashTable h, int key);
void removeKey(hashTable *h, int key);
void deleteHashTable(hashTable *h);