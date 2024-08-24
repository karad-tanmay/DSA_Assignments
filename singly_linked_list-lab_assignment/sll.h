typedef struct node {
    int data;
    struct node *next;
}node;

typedef node* list;

void swap(int *a, int *b);

void init(list *l);
int isEmpty(list l);
int len(list l);

// display funcs-
void display(list l);
// void traverse(list l); same as display
void display_list_node(list l); // for debugging
void display_node(node n, char *str); // for debugging

// insert funcs-
void append(list *l, int x); // insert at end*
void insert_at_beg(list *l, int x);
void insert_at_pos(list *l, int x, int index);

// remove funcs-
int remove_at_beg(list *l);
int remove_at_pos(list *l, int pos);
int remove_at_end(list *l);

void sort(list *l);
int lin_search(list l, int x);
void remove_dupl(list *l);

void free_list(list *l);
// int insert_at_position(list *l, int data, int index);
// void swap_node(list *l, int n1, int n2, node *curr1, node *curr2);
// void sort_list(list *l);