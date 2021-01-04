// needs to use pair of int

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
        return;
    else
    {
        Queue->size++;
        Queue->arr[Queue->rear++]=val;
    }
}

int dequeue(que* Queue)
{
    if(Queue->size==0)
        return 0;
    else
    {
        Queue->size--;
        Queue->front++;
        return Queue->arr[Queue->front-1];
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n,x,k,max_index,orignal_index=0;
    cin>>n>>x;
    int temp,rem[x];
    que* my_queue=create_queue(n);
    for(int i=0;i<n;i++)
        {
            cin>>temp;
            enqueue(my_queue,temp);
        }
    for(int i=0;i<x;i++)
    {
        if(x>my_queue->size)
        {
            for(int i=0;i<my_queue->size;i++)
                rem[i]=dequeue(my_queue);
        }
        else
        {
            for(int i=0;i<x;i++)
                rem[i]=dequeue(my_queue);

            k=rem[0];
            max_index=0;

            for(int i=0;i<x;i++)
            {
                if(k<rem[i])
                {
                    max_index=i;
                    k=rem[i];
                }
                enqueue(my_queue,rem[i]-1);
            }
            cout<<max_index+1+orignal_index<<"\n";

        }
    }
}
