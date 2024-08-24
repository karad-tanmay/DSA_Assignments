typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
}node;

typedef struct DLL{
    struct node *front;
    struct node *rear;
}DLL;

void swap(int *a, int *b);

void init(DLL *l);
void isEmpty(DLL l);
int len(DLL l);

// display funcs-
void display(DLL l);
void display_list_node(DLL l);
void display_node(node n, char *var_name);

// insert funcs-
void append(DLL *l, int x);
void insert_at_pos(DLL *l, int x, int index);
void insert_at_beg(DLL *l, int x);

// remove funcs-
int remove_at_beg(DLL *l);
int remove_at_pos(DLL *l, int index);
int remove_at_end(DLL *l);

int lin_search(DLL l, int x);
void sort_list(DLL *l);
int isPalindrome(DLL l);
void remove_dupl(DLL *l);

void free_list(DLL *l);