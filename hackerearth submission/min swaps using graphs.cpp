#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

typedef struct node{

    int val;
    struct node *next;
}n;

typedef struct l_list{
    struct node * head;
}l;

typedef struct  graph{
    int v;
    struct l_list *arr;
}g;

g* createGraph(int v)
{
    g* graph=(g*)malloc(sizeof(g));
    graph->v=v;
    graph->arr=(l*)malloc(v*sizeof(l));

    for(int i=0;i<v;i++)
        graph->arr[i].head=NULL;

    return graph;
}

void addEdge(g* graph,int from,int to)
{
    if(graph->arr[from].head==NULL)
    {
        graph->arr[from].head=(n*)malloc(sizeof(n));
        graph->arr[from].head->val=to;
        graph->arr[from].head->next=NULL;
    }
    else
    {
        n* cur=graph->arr[from].head;
        while(cur->next!=NULL)
            cur=cur->next;
        cur->next=(n*)malloc(sizeof(n));
        cur->next->val=to;
        cur->next->next=NULL;
    }
}

v

void min_swaps(int arr[], int n)
{
    g* my_graph=createGraph(n);
    int copy_array[n];
        for(int i=0;i<n;i++)
            copy_array[i]=arr[i];
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
     if(arr[i]!=copy_array[i])
        addEdge(my_graph,arr[i],copy_array[i]);
    }
}

int main()
{
    int arr[]={4,5,2,1,5};
    int n = (sizeof(arr) / sizeof(int));
    min_swaps(arr,n);
}
