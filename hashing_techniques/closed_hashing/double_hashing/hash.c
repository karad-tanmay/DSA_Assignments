#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int isPrime(int x){
    for (int i = 2; i < x; i++){
        if (x % i == 0)
            return 0;
    }
    return 1;
}

int getNearestPrime(int x){
    for(int i = x; i >= 2; i--){
        if(isPrime(i))
            return i;
    }
    return x;
}

void initHT(hashTable *h, int size){
    if(size <= 0)
        return;
    h->ht = (int*)calloc(size, sizeof(int));
    h->size = size;
    return;
}

int hash1(int key, int size){
    if(key < 0)
        key *= -1;
    return key % size;
}

int hash2(int key, int size){
    if(key < 0)
        key *= -1;
    int r = getNearestPrime(size - 1);
    return r - (key % r);
}

int probe(hashTable h, int key){
    int h1 = hash1(key, h.size);
    int h2 = hash2(key, h.size);
    int i = 0;
    while(h.ht[(h1 + (i * h2)) % h.size] != 0)
        i++;
    return (h1 + (i * h2)) % h.size;
}

void insertKey(hashTable *h, int key){
    int index = hash1(key, h->size);
    if(h->ht[index] != 0)
        index = probe(*h, key);
    h->ht[index] = key;
    return;
}

int searchKey(hashTable h, int key){
    int h1 = hash1(key, h.size);
    int h2 = hash2(key, h.size);
    int i = 0;
    while(h.ht[(h1 + (i * h2)) % h.size] != key && h.ht[(h1 + (i * h2)) % h.size] != 0)
        i++;
    if(h.ht[(h1 + (i * h2)) % h.size] == 0)
        return -1;
    else 
        return (h1 + (i * h2)) % h.size;
}

// void removeKey(hashTable *h, int key); to be skipped

void deleteHashTable(hashTable *h){
    free(h->ht);
    h->size = 0;
    return;
}