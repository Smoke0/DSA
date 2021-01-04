// this algorithm implementation  is pretty simple just run a loop but understanding algo is not that simple.

#include<iostream>
#include<cstdlib>
#include<limits.h>

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

void b_ford(graph* G, int src)
{
    int v = G->V;
    int e = G->E;
    int dis[G->V];

    dis[src] = 0;

    for(int i=1;i<v;i++)
        dis[i] = INT_MAX;

    for(int i=1;i<v-1;i++) // this loops process every edge v-1 times
    {
        for(int j=0;j<e;j++)  // this loops processes every edge one by one and assign distances as loop run more and more
                            // the distance get minimized and v-1 times ensures that its minimum distance.
        {
            int u = G->Edges[j].src;
            int v = G->Edges[j].des;
            int w = G->Edges[j].weight;
            if (dis[u]!= INT_MAX && dis[u] + w < dis[v])
                dis[v] = dis[u] + w;
        }
    }
    // In this algo the -ve are also considered
    // the algo is that if for every edge distance of destination pt. is more than distance from source + weight of edge b/w u-v then update it.
    for(int i=0;i<v;i++)
        cout<<"The dis from source of vertex "<<i<<" is  "<<dis[i]<<"\n";
}

int main()
{
    graph* my_graph = createGraph(5,8);

    my_graph->Edges[0].src = 0;
    my_graph->Edges[0].des = 1;
    my_graph->Edges[0].weight = -1;

    my_graph->Edges[1].src = 0;
    my_graph->Edges[1].des = 2;
    my_graph->Edges[1].weight = 4;

    my_graph->Edges[2].src = 1;
    my_graph->Edges[2].des = 2;
    my_graph->Edges[2].weight = 3;

    my_graph->Edges[3].src = 1;
    my_graph->Edges[3].des = 3;
    my_graph->Edges[3].weight = 2;

    my_graph->Edges[4].src = 1;
    my_graph->Edges[4].des = 4;
    my_graph->Edges[4].weight = 2;

    my_graph->Edges[5].src = 3;
    my_graph->Edges[5].des = 2;
    my_graph->Edges[5].weight = 5;

    my_graph->Edges[6].src = 3;
    my_graph->Edges[6].des = 1;
    my_graph->Edges[6].weight = 1;

    my_graph->Edges[7].src = 4;
    my_graph->Edges[7].des = 3;
    my_graph->Edges[7].weight = -3;

   b_ford(my_graph,0);
}
