#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct node{
  int val;
  struct node *next;
}n;

n* head=NULL;

void push(n** hpt,int x)
{
        if(*hpt==NULL)
        {
            (*hpt)=(n*)malloc(sizeof(n));
            (*hpt)->val=x;
            (*hpt)->next=NULL;
        }
        else
        {
            n* cur=*hpt;
            while(cur->next!=NULL)
            {
                cur=cur->next;
            }
            cur->next=(n*)malloc(sizeof(n));
            cur->next->val=x;
            cur->next->next=NULL;
        }
}

void print(n* head)
{
    n* cur = head;
    while(cur!=NULL)
    {
        cout<<cur->val;
        cur=cur->next;
    }

}

int main()
{
    push(&head,5);
    push(&head,6);
    push(&head,7);
    push(&head,8);
    print(head);

}

