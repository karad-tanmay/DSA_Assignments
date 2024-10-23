// Implement ADT Binary Search Tree(BST) using a linked list of nodes of structure having Month, left pointer, right pointer, and parent pointers pointing to left sub-trees, right sub-tree, and parent of the node.

// Perform a series of insertions on keys - December, January, April, March, July, August, October, February, November, May, June.  Write following functions: 

// initBST()         // to initialize the tree. 

// insertNode()    // non-recursive function to add a new node to the BST. 

// removeNode() // to remove a node from a tree. 

// traverse()         // write any of the non-recursive traversal methods.

// destroyTree()  // to delete all nodes of a tree.

// bst
typedef struct nodeBST{
    int month;
    struct nodeBST *left;
    struct nodeBST *right; 
    struct nodeBST *parent;
}nodeBST;

typedef nodeBST* BST;

void initBST(BST *t);
int BSTHeight(BST t);
nodeBST* getInPre(BST t);
nodeBST* getInSucc(BST t);
void insertNode(BST *t, int data);
void removeNode(BST *t, int data);
void preorderTraverse(BST t);
void inorderTraverse(BST t);
// void postorderTraverse(BST t);
void destroyTree(BST *t);

// stack
typedef struct node{
    nodeBST* nodeAdd;
    struct node* next;
}node;

typedef struct stack{
    struct node* top;
}stack;

void init(stack *s);
int isEmpty(stack s);
int len(stack s);
void push(stack *s, nodeBST *x);
nodeBST* pop(stack *s);
nodeBST* peek(stack s);
void displayStack(stack s);
void clearStack(stack *s);