// this is proper implementation of stack.

#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct Stack
{
    int top;
    unsigned int capacity;
    int *arr;
}stk;

stk* creat_stack(unsigned int capacity)
{
    stk* Stack =(stk*)malloc(sizeof(stk));
    Stack->capacity=capacity;
    Stack->top=-1;
    Stack->arr=(int*)malloc(capacity*sizeof(int));
}

void push(stk* Stack,int val)
{
    if(Stack->top+1==Stack->capacity)
        cout<<"Stack is full\n";
    else
        Stack->arr[++Stack->top]=val;
}

void pop(stk* Stack)
{
    if(Stack->top==-1)
        cout<<"stack is empty\n";
    else
        Stack->top--;
}

void print_stack(stk* Stack)
{
    for(int i=0;i<Stack->top+1;i++)
        cout<<Stack->arr[i]<<" ";
}

int main()
{
    stk* my_stack=creat_stack(5);
    //push(my_stack,1);
    //push(my_stack,2);
    //push(my_stack,3);
    //push(my_stack,13);
    //push(my_stack,14);
    pop(my_stack);
    print_stack(my_stack);
}
