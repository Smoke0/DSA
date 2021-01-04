//  this is a proper implementation of queue.
//  main is just for  testing the stuff out.
#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct Queue
{
    int front,rear,size;
    unsigned int capacity;
    int *arr;
}que;

que* create_queue(unsigned int capacity)
{
    que* Queue=(que*)malloc(sizeof(que));
    Queue->capacity=capacity;
    Queue->front=0;
    Queue->rear=0;
    Queue->size=0;
    Queue->arr=(int*)malloc(capacity*sizeof(int));
    return Queue;
}

void enqueue(que* Queue,int val)
{
    if(Queue->size==Queue->capacity)
        cout<<"Queue is full\n";
    else
    {
        Queue->size++;
        Queue->arr[Queue->rear++]=val;
    }
}

int dequeue(que* Queue)
{
    if(Queue->size==0)
        cout<<"Empty queue\n";
    else
    {
        Queue->size--;
        Queue->front++;
        return Queue->arr[Queue->front-1];
    }
}

void print_queue(que* Queue)
{
    for(int i=Queue->front;i<Queue->rear;i++)
        cout<<Queue->arr[i]<<" ";
}

int main()
{
    que* my_queue=create_queue(5);
    enqueue(my_queue,5);
    enqueue(my_queue,55);
    enqueue(my_queue,56);
    cout<<dequeue(my_queue)<<"\n";
    cout<<dequeue(my_queue)<<"\n";
    dequeue(my_queue);
    cout<<dequeue(my_queue)<<"\n";
    enqueue(my_queue,5);
    enqueue(my_queue,55);
    enqueue(my_queue,56);
    enqueue(my_queue,55);
    enqueue(my_queue,56);
    print_queue(my_queue);
}
