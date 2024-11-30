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

int hash(int key, int size){
    if(key < 0)
        key *= -1;
    return key % size;
}

void insertKey(hashTable *h, int key){
    if(key >= h->size)
        return;
    h->arr[hash(key, h->size)] = key;
    return;
}

int searchKey(hashTable h, int key){
    if(key >= h.size)
        return -1;
    if(h.arr[hash(key, h.size)] == key)
        return hash(key, h.size);
    return -1;
}

void removeKey(hashTable *h, int key){
    if(key >= h->size)
        return;
    h->arr[hash(key, h->size)] = 0;
    return;
}

void deleteHashTable(hashTable *h){
    h->size = 0;
    free(h->arr);
    h->arr = NULL;
    return;
}