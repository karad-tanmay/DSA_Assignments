#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

node* createNode(int data);
int isEmpty(node *root);

node* insertNode(node* root, int data); 
node* searchNode(node* root, int key);
node* deleteNode(node* root, int key); 
node* findMinNode(node* root);
node* findMaxNode(node* root);
void inorderTraversal(node* root);
void preorderTraversal(node* root);
void postorderTraversal(node* root);
node* destroyTree(node* root);