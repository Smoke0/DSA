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

void del(n** hpt,int val)
{
    n* cur=*hpt;
    if(cur->val==val)
    {
        cur=cur->next;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,temp;
    cin>>t;
    n* cur=head;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            push(&head,temp);
        }
        while(k--)
        {
            while(cur->next!=NULL)
            {
                if(cur->val<cur->next->val);

            }
        }

    }

}

