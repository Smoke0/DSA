// this is 2nd one with pointers far better than other one and works fine.
#include<iostream>

using namespace std;

void in(int que[],int size,int element,int *rear)
{
    if(*rear==size-1)
        cout<<"It's full"<<endl;
    else
    {
        que[*rear]=element;
        (*rear)++;
    }
}
void out(int que[],int size,int *front,int *rear)
{
    if(*rear==*front)
        cout<<"it's empty"<<endl;
    else
        (*front)++;
}
int front(int que[],int size,int *front)
{
    return que[*front];
}
bool isempty(int que[],int size,int *rear)
{
    if(*rear==0)
        return true;
    else
        return false;
}
int si(int que[],int size,int *front,int *rear) ////returns size of queue.
{
   return (*rear)-(*front);
}
int main()
{
    cout<<"enter size of queue"<<endl;
    int size;
    cin>>size;
    int que[size];
    int f=0,r=0;
    in(que,size,6,&r);
    in(que,size,7,&r);
    out(que,size,&f,&r);
    int a;
    a=si(que,size,&f,&r);
    cout<<a;


}

