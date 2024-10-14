#include <stdlib.h>
#include <string.h>

typedef struct node{
    struct node *links[26];
    int isEndOfWord;
}node;

typedef node* trie;

int containsKey(node *p, char ch);
void createNode(trie *t);
void insertWord(trie *t, char *data);
int searchWord(trie t, char *key);
int startsWith(trie t, char *key);
void displayTrie(trie t, char *prefix, int length);
// void deleteWord(trie *t, char *key);
void freeTrie(trie *t);