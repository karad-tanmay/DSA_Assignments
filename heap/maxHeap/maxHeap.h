typedef struct maxHeap{
    int size;
    int *arr;
    int rear;
} maxHeap;

void init(maxHeap *h, int size);
int getParentIndex(maxHeap h, int i);
void insert(maxHeap *h, int data);
int remove_ele(maxHeap *h);
void heapSort(maxHeap *h);
void deleteHeap(maxHeap *h);

void displayArray(maxHeap h);