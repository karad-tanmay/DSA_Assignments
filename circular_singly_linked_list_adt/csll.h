typedef struct node{
    int data;
    struct node* next;
}node;

typedef node* list;

void swap(int *a, int *b);

void init(list *l); //done
int isEmpty(list l); //done
int len(list l); //done

void display(list l); //done
void display_list_node(list l); //done

void append(list *l, int x); //done
void insert_at_pos(list *l, int x, int index); //done
void insert_at_beg(list *l, int x); //done

int remove_at_beg(list *l); //done
int remove_at_pos(list *l, int index); //done
int remove_at_end(list *l); //done

int lin_search(list l, int x); //done
// void sort(list *l);
// void remove_dupl(list *l);

void merge_list(list l1, list l2, list *l3);
void shift_left(list *l); //done

void free_list(list *l); //done