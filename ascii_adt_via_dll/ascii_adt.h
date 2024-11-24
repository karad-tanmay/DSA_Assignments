typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;

typedef struct DLL
{
    struct node *front;
    struct node *rear;
} DLL;

void init_ASCII(DLL *l); // done
int isEmpty(DLL l);      // done
int len(DLL l);          // done
void ASCII_of(char c, DLL *l);
void insert_at_beg(DLL *l, int x); // done
void traverse(DLL l);              // done
void destroy(DLL *l);              // done
