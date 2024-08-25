typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
}node;

typedef struct DLL{
    struct node *front;
    struct node *rear;
}DLL;

void swap(int *a, int *b); //done

void init(DLL *l); //done
int isEmpty(DLL l); //done
int len(DLL l); //done

// display funcs-
void display_lr(DLL l); //done
void display_rl(DLL l); //done
void display_list_node(DLL l); //done
void display_node(node n, char *var_name);

// insert funcs-
void append(DLL *l, int x); //done
void insert_at_pos(DLL *l, int x, int index); //done
void insert_at_beg(DLL *l, int x); //done

// remove funcs-
int remove_at_beg(DLL *l); //done
int remove_at_pos(DLL *l, int index); //done
int remove_at_end(DLL *l); //done

int lin_search(DLL l, int x); //done
void sort_list(DLL *l); //done
int isPalindrome(DLL l); //done
void remove_dupl(DLL *l); //done
void remove_dupl_func(DLL *l); //done

void free_list(DLL *l); //done