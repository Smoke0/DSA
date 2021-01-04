// this is graph implementation but it's for a undirected graph
// to make it directive disable 2nd if else block of addedge.

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

void printgraph(g* graph)     //Just prints graph.
{
    for(int i=0;i<graph->v;i++)
    {
        cout<<endl<<"Linked list of vertex "<<i<<":"<<endl<<" Head ";
        n* cur=graph->arr[i].head;
        while(cur!=NULL)
        {
            cout<<"->"<<cur->val<<" ";
            cur=cur->next;
        }
    }
}

int main()
{
    int V = 5;
    struct graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printgraph(graph);
    return 0;
}
