typedef struct hashTable{
    int size;
    int *ht;
}hashTable;

int isPrime(int x);
int getNearestPrime(int x);
void initHT(hashTable *h, int size);
int hash1(int key, int size);
int hash2(int key, int size);
int probe(hashTable h, int key);
void insertKey(hashTable *h, int key);
int searchKey(hashTable h, int key);
// void removeKey(hashTable *h, int key); to be skipped
void deleteHashTable(hashTable *h);