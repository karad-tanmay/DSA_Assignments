#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "hash.h"

void init(hashTable *h, int size){
    if(size <= 0)
        return;
    h->size = size;
    h->arr = (int*)calloc(size, sizeof(int));
    return;
}

int hash(int key){
    if(key >= 0)
        return key;
    return 0;
}

void insertKey(hashTable *h, int key){
    if(key >= h->size)
        return;
    h->arr[hash(key)] = key;
    return;
}

int searchKey(hashTable h, int key){
    if(key >= h.size)
        return -1;
    if(h.arr[hash(key)] == key)
        return hash(key);
    return -1;
}

void removeKey(hashTable *h, int key){
    if(key >= h->size)
        return;
    h->arr[hash(key)] = INT_MIN;
    return;
}

void deleteHashTable(hashTable *h){
    h->size = 0;
    free(h->arr);
    h->arr = NULL;
    return;
}