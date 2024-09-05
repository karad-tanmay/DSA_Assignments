typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

node* createNode(int data); //Initializes a new node with the provided data and sets its left and right child pointers to NULL. This is a helper function that will be used internally for other operations.
int isEmpty(node *root); //Checks if the BST is empty (i.e., if the root is NULL). Returns 1 if empty, 0 otherwise.

node* insertNode(node* root, int data); //Adds a new node with the given data to the BST, starting from the root. The function returns the updated root pointer to ensure the tree remains intact.
node* searchNode(node* root, int key); //Searches the BST for a node containing the specified key. It returns a pointer to the found node or NULL if the key does not exist in the tree
node* deleteNode(node* root, int key); //Removes the node with the specified key from the BST, rearranging the nodes as necessary to maintain the BST properties. The function returns the updated root pointer.
node* findMinNode(node* root); //Returns a pointer to the node with the smallest value in the BST. This is useful for various operations, such as finding an in-order successor.
node* findMaxNode(node* root); //Returns a pointer to the node with the largest value in the BST. This function is typically used to find the rightmost node.
void inorderTraversal(node* root); //Performs an inorder traversal of the BST, visiting nodes in sorted order (left-root-right). This function is commonly used to print the elements of the tree in ascending order.
void preorderTraversal(node* root); //Conducts a preorder traversal of the BST, visiting nodes in "root-left-right" order. Useful for tasks that require processing the parent node before the child nodes.
void postorderTraversal(node* root); //Conducts a postorder traversal of the BST, visiting nodes in "left-right-root" order. This is useful for tasks such as freeing the tree or processing child nodes before the parent node.
node* destroyTree(node* root);
