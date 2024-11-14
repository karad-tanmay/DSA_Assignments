#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

void initHT(hashTable *h, int size){
    if(size <= 0)
        return;
    h->ht = (int*)calloc(size, sizeof(int));
    h->size = size;
    return;
}

int hash(int key, int size){
    if(key < 0)
        key *= -1;
    return key % size;
}

int probe(hashTable h, int key){
    int index = hash(key, h.size);
    int i = 0;
    while(h.ht[(index + i) % h.size] != 0)
        i++;
    return (index + i) % h.size;
}

void insertKey(hashTable *h, int key){
    int index = hash(key, h->size);
    if(h->ht[index] != 0)
        index = probe(*h, key);
    h->ht[index] = key;
    return;
}

int searchKey(hashTable h, int key){
    int index = hash(key, h.size);
    int i = 0;
    while(h.ht[(index + i) % h.size] != key && h.ht[(index + i) % h.size] != 0)
        i++;
    if(h.ht[(index + i) % h.size] == 0)
        return -1;
    else 
        return (index + i) % h.size;
}

// void removeKey(hashTable *h, int key); to be skipped

void deleteHashTable(hashTable *h){
    free(h->ht);
    h->size = 0;
    return;
}