typedef struct node{
    int data;
    struct node* next;
}node;

typedef node* list;

void swap(int *a, int *b);

void init(list *l);
int isEmpty(list l);
int len(list l);

void append(list *l, int x);
void insert_at_pos(list *l, int x, int index);
void insert_at_beg(list *l, int x);

int remove_at_beg(list *l);
int remove_at_pos(list *l, int index);
int remove_at_end(list *l);

int lin_search(list l, int x);
void sort(list *l);
void remove_dupl(list *l);

void merge_list(list l1, list l2, list *l3);

void free_list(list *l);