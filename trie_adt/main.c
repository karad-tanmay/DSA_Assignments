#include <stdio.h>
#include "trie.h"

int main(){
    trie t;
    char *a = (char*)malloc(sizeof(char) * 64);
    createNode(&t); // create node function also works as the init func for trie;
    insertWord(&t, "insert");
    insertWord(&t, "inert");
    insertWord(&t, "install");
    insertWord(&t, "tanny");
    insertWord(&t, "ohboi");
    printf("is present: %d\n", searchWord(t, "insert"));
    printf("is present: %d\n", startsWith(t, "ins"));
    displayTrie(t, a, 0);
    freeTrie(&t);
    printf("test0\n");
    return 0;
}