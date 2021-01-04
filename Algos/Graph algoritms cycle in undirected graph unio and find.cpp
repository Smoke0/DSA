#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

typedef struct Edge
{
    int src,des,weight;
}edge;

typedef struct Graph
{
    int V,E;

    edge* Edges;
}graph;

graph* createGraph(int V,int E)
{
    graph* G = (graph*)malloc(sizeof(graph));

    G->V = V;
    G->E = E;

    G->Edges = (edge*)malloc(E*sizeof(edge));

    return G;
}

int Find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return Find(parent, parent[i]);
}

void Union(int parent[], int x, int y)
{
    int xset = Find(parent, x);
    int yset = Find(parent, y);
    parent[xset] = yset;
}

bool isCyclic(graph* G)
{
    int parent[G->V];

    for(int i=0;i<G->V;i++)
        parent[i] = -1;

    for(int i=0;i<G->V;i++)
    {
        int x = Find(parent,G->Edges[i].src);
        int y = Find(parent,G->Edges[i].des);

        if (x==y)
            return true;
        Union(parent,x,y);
    }
    return false;
}
