// Dijkastra use same ds as the prim algo so implemented in same file.

// it's a copy from geeks for geeks mostly
// First we create heap and graphs and then we simply use a function to implement the prim
#include<iostream>
#include<cstdlib>
#include<climits>

using namespace std;

// I would use standard heap node but in prim we need a key value also so need to create a new structure.
typedef struct MinHeapNode {
    int v;
    int key;
}HeapNode;

// Structure to represent a min heap
typedef struct MinHeap {
    int size; // Number of heap nodes present currently
    int capacity; // Capacity of min heap
    int* pos; // This is needed for decreaseKey()
    HeapNode** arr;
}MinHeap;

// A utility function to create a new Min Heap Node
HeapNode* newMinHeapNode(int v, int key)
{
    struct MinHeapNode* minHeapNode = (HeapNode*)malloc(sizeof(HeapNode));
    minHeapNode->v = v;
    minHeapNode->key = key;
    return minHeapNode;
}

// A utility function to create a Min Heap
MinHeap* createMinHeap(int capacity)
{
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->pos = (int*)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->arr = (HeapNode**)malloc(capacity * sizeof(HeapNode*));
    return minHeap;
}

// A utility function to swap two nodes of min heap. Needed for min heapify
void swapMinHeapNode(HeapNode** a,HeapNode** b)
{
    HeapNode* t = *a;
    *a = *b;
    *b = t;
}

// A standard function to heapify at given idx
// This function also updates position of nodes when they are swapped.
// Position is needed for decreaseKey()
void minHeapify(MinHeap* minHeap, int index)
{
    int smallest, left, right;
    smallest = index;
    left = 2 * index + 1;
    right = 2 * index + 2;

    if (left < minHeap->size && minHeap->arr[left]->key < minHeap->arr[smallest]->key)
        smallest = left;

    if (right < minHeap->size && minHeap->arr[right]->key < minHeap->arr[smallest]->key)
        smallest = right;

    if (smallest != index) {
        // The nodes to be swapped in min heap
        MinHeapNode* smallestNode = minHeap->arr[smallest];
        MinHeapNode* idxNode = minHeap->arr[index];

        // Swap positions
        minHeap->pos[smallestNode->v] = index;
        minHeap->pos[idxNode->v] = smallest;

        // Swap nodes
        swapMinHeapNode(&minHeap->arr[smallest], &minHeap->arr[index]);

        minHeapify(minHeap, smallest);
    }
}

// A utility function to check if the given minHeap is ampty or not
int isEmpty(MinHeap* minHeap)
{
    return minHeap->size == 0;
}

// Standard function to extract minimum node from heap
HeapNode* extractMin(MinHeap* minHeap)
{
    if (isEmpty(minHeap))
        return NULL;

    // Store the root node
    HeapNode* root = minHeap->arr[0];

    // Replace root node with last node
    HeapNode* lastNode = minHeap->arr[minHeap->size - 1];
    minHeap->arr[0] = lastNode;

    // Update position of last node
    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;

    // Reduce heap size and heapify root
    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

// Function to decreasy key value of a given vertex v. This function
// uses pos[] of min heap to get the current index of node in min heap
void decreaseKey(MinHeap* minHeap, int v, int key)
{
    // Get the index of v in  heap array
    int i = minHeap->pos[v];

    // Get the node and update its key value
    minHeap->arr[i]->key = key;

    // Travel up while the complete tree is not hepified.
    // This is a O(Logn) loop
    while (i && minHeap->arr[i]->key < minHeap->arr[(i - 1) / 2]->key) {
        // Swap this node with its parent
        minHeap->pos[minHeap->arr[i]->v] = (i - 1) / 2;
        minHeap->pos[minHeap->arr[(i - 1) / 2]->v] = i;
        swapMinHeapNode(&minHeap->arr[i], &minHeap->arr[(i - 1) / 2]);

        // move to parent index
        i = (i - 1) / 2;
    }
}

// A utility function to check if a given vertex
// 'v' is in min heap or not
bool isInMinHeap(MinHeap* minHeap, int v)
{
    if (minHeap->pos[v] < minHeap->size)
        return true;
    return false;
}

typedef struct Node{

    int val,weight;
    struct Node *next;
}node;

typedef struct L_List{
    struct Node * head;
}l_list;

typedef struct  Graph{
    int v;
    struct L_List *arr;
}graph;

node* CreateNode(int value,int weight)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->val = value;
    temp->weight = weight;
    temp->next = NULL;

    return temp;
}

graph* CreateGraph(int V)
{
    graph* temp = (graph*)malloc(sizeof(graph));
    temp->v = V;
    temp->arr  = (l_list*)malloc(V*sizeof(l_list));

    for(int i=0;i<V;i++)
        temp->arr[i].head = NULL;

    return temp;
}

void AddEdge(graph* temp, int src, int des, int weight)
{
    node* n = CreateNode(des,weight);
    n->next = temp->arr[src].head;
    temp->arr[src].head = n;

    n = CreateNode(src,weight);
    n->next = temp->arr[des].head;
    temp->arr[des].head = n;
}

// The main function that constructs Minimum Spanning Tree (MST)
// using Prim's algorithm
void PrimMST(graph* my_graph)
{
    int V = my_graph->v; // Get the number of vertex in graph
    int parent[V]; // Array to store constructed MST
    int key[V]; // Key values used to pick minimum weight edge in cut

    // minHeap represents set E
    MinHeap* minHeap = createMinHeap(V);

    // Initialize min heap with all vertices. Key value of
    // all vertices (except 0th vertex) is initially infinite
    for (int v = 1; v < V; ++v) {
        parent[v] = -1;
        key[v] = INT_MAX;
        minHeap->arr[v] = newMinHeapNode(v, key[v]);
        minHeap->pos[v] = v;
    }

    // Make key value of 0th vertex as 0 so that it
    // is extracted first
    key[0] = 0;
    minHeap->arr[0] = newMinHeapNode(0, key[0]);
    minHeap->pos[0] = 0;

    // Initially size of min heap is equal to V
    minHeap->size = V;

    // In the followin loop, min heap contains all nodes
    // not yet added to MST.
    while (!isEmpty(minHeap))  // this loop is the prim algorithm rest is else.
        {
        // Extract the vertex with minimum key value
        HeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v; // Store the extracted vertex number

        // Traverse through all adjacent vertex of u (the extracted
        // vertex) and update their key values
        node* cur = my_graph->arr[u].head;
        while (cur != NULL) {
            int v = cur->val;

            // If v is not yet included in MST and weight of u-v is
            // less than key value of v, then update key value and
            // parent of v
            if (isInMinHeap(minHeap, v) && cur->weight < key[v]) {
                key[v] = cur->weight;
                parent[v] = u;
                decreaseKey(minHeap, v, key[v]);
            }
            cur = cur->next;
        }
    }
    for (int i=1;i<V;i++)
        cout<<parent[i]<<"-"<<i<<"\n";
}

void Dijkastra(graph* my_graph, int source)
{
    int no_of_vertex = my_graph->v;
    int DistanceArray[no_of_vertex];

    MinHeap* my_heap = createMinHeap(no_of_vertex);

    my_heap->arr[source]  = newMinHeapNode(source,DistanceArray[source]);
    my_heap->pos[source] = source;
    DistanceArray[source] = 0;
    for(int i=1;i<my_graph->v;i++)
    {
        DistanceArray[i] = INT_MAX;
        my_heap->arr[my_graph->v] = newMinHeapNode(i,DistanceArray[i]);
        my_heap->pos[i] = i;
    }

    my_heap->size = no_of_vertex;

    /*while(!isEmpty(my_heap))
    {

        HeapNode* MinNode = extractMin(my_heap);
        int min_vertex = MinNode->v;
        node* cur = my_graph->arr[min_vertex].head;

        while(cur!=NULL)
        {
            int v = cur->val;
            if(isInMinHeap(my_heap,v && DistanceArray[min_vertex]!=INT_MAX && cur->weight + DistanceArray[min_vertex]<DistanceArray[v]))
            {
                DistanceArray[v] = DistanceArray[min_vertex] + cur->weight;
                decreaseKey(my_heap,v,DistanceArray[v]);
            }
            cur = cur->next;
        }*/
    //}
    //for (int i=0;i<my_graph->v;i++)
      //  cout<<"Distance from vertex is "<<i<<"-"<<DistanceArray[i]<<"\n";
}


int main()
{
    graph* graph = CreateGraph(9);
    AddEdge(graph, 0, 1, 4);
    AddEdge(graph, 0, 7, 8);
    AddEdge(graph, 1, 2, 8);
    AddEdge(graph, 1, 7, 11);
    AddEdge(graph, 2, 3, 7);
    AddEdge(graph, 2, 8, 2);
    AddEdge(graph, 2, 5, 4);
    AddEdge(graph, 3, 4, 9);
    AddEdge(graph, 3, 5, 14);
    AddEdge(graph, 4, 5, 10);
    AddEdge(graph, 5, 6, 2);
    AddEdge(graph, 6, 7, 1);
    AddEdge(graph, 6, 8, 6);
    AddEdge(graph, 7, 8, 7);
    //PrimMST(graph);
    Dijkastra(graph,0);
    return 0;
}
