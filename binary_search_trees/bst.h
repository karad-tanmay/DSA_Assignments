typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

typedef node *tree;

void init(tree *t);
// node* createNode(int data); //Initializes a new node with the provided data and sets its left and right child pointers to NULL. This is a helper function that will be used internally for other operations.
int isEmpty(tree t); //Checks if the BST is empty (i.e., if the root is NULL). Returns 1 if empty, 0 otherwise.

void insertNode(tree *t, int data); //Adds a new node with the given data to the BST, starting from the root. The function returns the updated root pointer to ensure the tree remains intact.
node* searchNode(tree t, int key); //Searches the BST for a node containing the specified key. It returns a pointer to the found node or NULL if the key does not exist in the tree
// int deleteNode(tree *t, int key); //Removes the node with the specified key from the BST, rearranging the nodes as necessary to maintain the BST properties. The function returns the updated root pointer.
node* findMinNode(tree t); //Returns a pointer to the node with the smallest value in the BST. This is useful for various operations, such as finding an in-order successor.
node* findMaxNode(tree t); //Returns a pointer to the node with the largest value in the BST. This function is typically used to find the rightmost node.
void inorderTraversal(tree t); //Performs an inorder traversal of the BST, visiting nodes in sorted order (left-root-right). This function is commonly used to print the elements of the tree in ascending order.
void preorderTraversal(tree t); //Conducts a preorder traversal of the BST, visiting nodes in "root-left-right" order. Useful for tasks that require processing the parent node before the child nodes.
void postorderTraversal(tree t); //Conducts a postorder traversal of the BST, visiting nodes in "left-right-root" order. This is useful for tasks such as freeing the tree or processing child nodes before the parent node.
void destroyTree(tree *t);