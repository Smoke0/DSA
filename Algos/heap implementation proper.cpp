#include<iostream>
#include<cstdlib>
#include<climits>
#define L_child(x) 2*x+1
#define R_child(x) 2*x+2
#define Parent(x) (x-1)/2

using namespace std;

typedef struct Heaps
{
    unsigned int capacity,size;
    int* arr;
}heap;

heap* createHeap(int capacity)
{
    heap* temp = (heap*)malloc(sizeof(heap));
    temp->capacity = capacity;
    temp->size = 0;
    temp->arr = (int*)malloc(capacity*sizeof(int));
}

void insertKey(heap* temp,int key)
{
    if(temp->size==temp->capacity)
       {
        cout<<"Overflow\n";
        return;
       }
    int i = temp->size++;
    temp->arr[i] = key;

    while (i!=0 && temp->arr[Parent(i)]>temp->arr[i])
    {
        swap(temp->arr[i],temp->arr[Parent(i)]);
        i = Parent(i);
    }
}

void decreaseKey(heap* temp,int i,int new_val)
{
    temp->arr[i] = new_val;
    while(i!=0 && temp->arr[Parent(i)]>temp->arr[i])
    {
        swap(temp->arr[i],temp->arr[Parent(i)]);
        i = Parent(i);
    }
}

void MinHeapify(heap*temp,int i)
{
    int l = L_child(i);
    int r = R_child(i);
    int smallest = i;
    if(l<temp->size && temp->arr[l] < temp->arr[i])
        smallest = l;
    if (r<temp->size && temp->arr[r] < temp->arr[smallest])
        smallest = r;
    if (smallest!=i)
    {
        swap(temp->arr[i],temp->arr[smallest]);
        MinHeapify(temp,smallest);
    }
}

int extractMin(heap* temp)
{
    if(temp->size==0){
        cout<<"Heap is empty\n";
        return -1;}
    if(temp->size==1){
        temp->size--;
        return temp->arr[0];}

    int min = temp->arr[0];
    temp->arr[0] = temp->arr[temp->size-1];
    temp->size--;
    MinHeapify(temp,0);

    return min;
}

void deleteKey(heap* temp, int i)
{
    decreaseKey(temp,i,INT_MIN);
    extractMin(temp);
}


int main()
{
    heap* myHeap = createHeap(10);
    insertKey(myHeap,3);
    //insertKey(myHeap,2);
    deleteKey(myHeap,0);
    insertKey(myHeap,15);
    insertKey(myHeap,5);
    insertKey(myHeap,4);
    insertKey(myHeap,45);
    //cout<<myHeap->size;

    cout<<extractMin(myHeap);
    decreaseKey(myHeap,3,1);
    cout<<extractMin(myHeap);
    return 0;
}

