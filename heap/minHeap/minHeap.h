typedef struct{
	int size;
	int *arr;
	int rear;
}minHeap;

void initHeap(minHeap *h, int size);
int getParent(int i);
void insert(minHeap *h, int data);
int removeEle(minHeap *h);
void heapify(minHeap *h, int i, int size);
void heapSort(minHeap *h);
void deleteHeap(minHeap *h);
void displayHeap(minHeap h);
