typedef struct bst{
    int size;
    int *a;
}bst;

void init(bst *t, int size);
void insert(bst *t, int data, int i);
void inorder_traversal(bst t, int i);
void preorder_traversal(bst t, int i);
void postorder_traversal(bst t, int i);
void destroyBST(bst *t);