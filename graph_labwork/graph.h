typedef struct node{
    char vertex;
    int edgeWeight;
    struct node* next;
}node;

typedef struct graph{
    int size;
    node **arr;
}graph;

int get_index(char ch);
void initGraph(graph *g, int size);
void insertEdge(graph *g, char start, char end, int weight);
void insertUndirectedEdge(graph *g, char start, char end, int weight);
void removeEdge(graph *g, char start, char end);
void removeUndirectedEdge(graph *g, char start, char end);
void graphBFS(graph g, char start);
void graphDFS(graph g, char start);
void displayGraph(graph g);
void deleteGraph(graph *g);