#include "hash.h"

void initHT(hashTable *h, int size){
    if(size <= 0)
        return;
    h->ht = (list*)calloc(size, sizeof(node*));
    h->size = size;
    return;
}

int hash(int key, int size){
    if(key < 0)
        key *= -1;
    return key % size;
}

void insertKey(hashTable *h, int key){
    int index = hash(key, h->size);
    int i = 0;
    // printf("index: %d\n", index);
    node *p = h->ht[index];
    while(p != NULL && p->data < key){
        i++;
        p = p->next;
    }
    // printf("i: %d\n", i);
    insert_at_pos(&(h->ht[index]), key, i);
    // printf("test5\n");
    return;
}

int searchKey(hashTable h, int key){
    int index = hash(key, h.size);
    node *p = h.ht[index];
    while(p != NULL){
        if(p->data == key)
            return index;
        else if(p->data > key)
            return -1;
        p = p->next;
    }
    return -1;
}

// needs to be checked
void removeKey(hashTable *h, int key){
    int index = hash(key, h->size);
    node *p = h->ht[index], *q;
    if(p == NULL || key < p->data)
        return;
    if(p->data == key){
        h->ht[index] = p->next;
        free(p);
        return;
    }
    q = p;
    p = p->next;
    while(p != NULL && p->data < key){
        q = p;
        p = p->next;
    }
    if(p->data == key){
        q->next = p->next;
        free(p);
        return;
    }
    return;
}

void deleteHashTable(hashTable *h){
    for(int i = 0; i < h->size; i++)
        free_list(&(h->ht[i]));
    h->size = 0;
    return;
}