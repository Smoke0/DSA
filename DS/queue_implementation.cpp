// first implementation of queue and it works fine.
// stuff inside main is for testing only.
#include<iostream>

using namespace std;

int f=0,r=0;
void in(int que[10],int x)
{
    if(r==9)
        cout<<"It's full"<<endl;
    else
    {
        que[r]=x;
        r++;
    }
}
void out(int que[10])
{
    if(r==f)
        cout<<"it's empty"<<endl;
    else
        f++;
}
int front(int que[10])
{
    return que[f];
}
bool isempty(int que[10])
{
    if(r==0)
        return true;
    else
        return false;
}
int size(int que[10])
{
   return r-f;
}
int main()
{
    int que[10],a;
    bool b;
    in(que,6);
    in(que,20);
    b=isempty(que);
    cout<<b;
}
