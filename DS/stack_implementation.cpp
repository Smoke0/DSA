/* It's my first implementation of stack but it works perfectly*/
// important things are function stuff inside main is random and for testing.

#include<iostream>
#define MAX 999
using namespace std;
int top = -1;
void push( int stk[],int n,int x)
{
    if(top==MAX)
    {
        cout<<"Stack is full"<<endl;
    }
    else
    {
        top+=1;
        stk[top]=x;
    }

}
void pop(int stk[],int n)
{
    if(top<0)
        cout<<"stack is empty"<<endl;
    else
    {
        top=top-1;
    }

}
int top_element(int stk[],int n)
{
    if (top>=0)
    return stk[top];
}
bool isempty(int stk[],int n)
{
    if (top<0)
        return true;
    else
        return false;

}
int size(int stk[],int n)
{
    return top+1;
}
int main()
{
    int stk[1000],a;
    push(stk,1000,5);
    push(stk,1000,6);
    cout<<stk[0]<<stk[1];
    pop(stk,1000);
    a=top_element(stk,1000);
    cout<<a;
    return 0;
}
