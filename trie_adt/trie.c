#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

int containsKey(node *p, char ch){
    return (p->links[(int)ch - 'a'] != NULL);
}

void createNode(trie *t){
    *t = (node*)malloc(sizeof(node));
    if(*t){
        for(int i = 0; i < 26; i++)
            (*t)->links[i] = NULL;
        (*t)->isEndOfWord = 0;
    }
    return;
}

void insertWord(trie *t, char *data){
    int len = strlen(data);
    if(len == 0)
        return;
    node *p = *t;
    for(int i = 0; i < len; i++){
        if(data[i] < 'a' || data[i] > 'z')
            return;
        if(containsKey(p, data[i]))
            p = p->links[(int)data[i] - 'a'];
        else{
            createNode(&p->links[(int)data[i] - 'a']);
            p = p->links[(int)data[i] - 'a'];
        }
    }
    p->isEndOfWord = 1;
    return;
}

int searchWord(trie t, char *key){
    int len = strlen(key);
    if(len == 0)
        return 0;
    node *p = t;
    for(int i = 0; i < len; i++){
        if(key[i] < 'a' || key[i] > 'z')
            return 0;
        if(!containsKey(p, key[i]))
            return 0;
        p = p->links[(int)key[i] - 'a'];
    }
    if(!p->isEndOfWord)
        return 0;
    return 1;
}

int startsWith(trie t, char *key){
    int len = strlen(key);
    if(len == 0)
        return 0;
    node *p = t;
    for(int i = 0; i < len; i++){
        if(key[i] < 'a' || key[i] > 'z')
            return 0;
        if(!containsKey(p, key[i]))
            return 0;
        p = p->links[(int)key[i] - 'a'];
    }
    return 1;
}

// void deleteWord(trie *t, char *key){

// }

void displayTrie(trie t, char *prefix, int length){
    if(t == NULL)
        return;
    if(t->isEndOfWord){
        prefix[length] = '\0';
        printf("%s\n", prefix);
    }
    for(int i = 0; i < 26; i++){
        if(t->links[i] != NULL){
            prefix[length] = 'a' + i;
            displayTrie(t->links[i], prefix, length + 1);
        }
    }
}

void freeTrie(trie *t){
    if(*t == NULL)
        return;
    for(int i = 0; i < 26; i++){
        if((*t)->links[i] != NULL)
            freeTrie(&((*t)->links[i]));
    }
    free(*t);
    *t = NULL;
    return;
}