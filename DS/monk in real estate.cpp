#include<iostream>
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

void addEdge(g* graph,int from,int to)   //adds edge.
{
    // adds edge from to to.
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
    // adds a edge from to to from
    if(graph->arr[to].head==NULL)
    {
        graph->arr[to].head=(n*)malloc(sizeof(n));
        graph->arr[to].head->val=from;
        graph->arr[to].head->next=NULL;
    }
    else
    {
        n* cur=graph->arr[to].head;
        while(cur->next!=NULL)
            cur=cur->next;
        cur->next=(n*)malloc(sizeof(n));
        cur->next->val=from;
        cur->next->next=NULL;
    }
}

int no_cities(g* graph)
{
    int cities=0;

    for(int i=0;i<graph->v;i++)
    {
        n* cur=graph->arr[i].head;
        if(cur!=NULL)
            cities++;
    }
    return cities;
}

int main()
{
    int t,e;
    int x,y;
    cin>>t;
    while(t--)
    {
        cin>>e;
        struct graph* graph = createGraph(e+2);

        for(int i=0;i<e;i++)
        {
            cin>>x>>y;
            addEdge(graph,x,y);
        }
        cout<<no_cities(graph)<<"\n";
    }

}
