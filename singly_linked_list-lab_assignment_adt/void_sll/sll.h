typedef struct {
    void *data;
    struct nodeSLL *next;
} nodeSLL;

typedef nodeSLL* SLL;

void init(SLL *l);
int isEmpty(SLL l);
int len(SLL l);
void insert(SLL *l, void *dataPtr, int index);
void* remove(SLL *l, int index);
void deleteList(SLL *l);

// for debugging -
void displayPtrs(SLL l);