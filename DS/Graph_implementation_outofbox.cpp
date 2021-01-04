// Graphs implementation using adjacency list implementation.
#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct node
{
    int val;
    struct node *next;
}n;

n** Graph(int v)
{
    n* arr[v];

    for(int i=0;i<v;i++)
        arr[i]=NULL;
    for(int i=0;i<v;i++)
       // cout<<arr[i]<<endl;
    return arr;
}


void addEdge(n** graph,int from,int to)
{

}


void printgraph(n** graph,int v)
{
    for(int i=0;i<v;i++)
    {
        while(graph[i]!=NULL)
        {
            cout<<graph[i]->val;
            graph[i]=graph[i]->next;
        }
        cout<<endl;
    }
}


int main()
{
    n** arr=Graph(5);
        cout<<*(arr+1)<<endl;
        cout<<*(arr+1)<<endl;
    //cout<<graph;
  /* addEdge(graph,2,3);
    addEdge(graph,2,4);
    addEdge(graph,1,2);
    addEdge(graph,1,3);
    addEdge(graph,3,4);
    addEdge(graph,3,2);
    addEdge(graph,4,0);
    addEdge(graph,4,1);*/
    //cout<<graph[4]<<endl;
    //printgraph(graph,5);

    return 0;
}

