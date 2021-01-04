// My implementation of Kruskal MST.
#include<iostream>
#include<cstdlib>


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

bool isCyclic(graph* G,int edges[], int j)
{
    //cout<<"is Cyclic Called \n";
    int parent[G->V];

    for(int i=0;i<G->V;i++)
        parent[i] = -1;

    for(int i=0;i<j;i++)
    {
        int x = Find(parent,G->Edges[edges[i]].src);
        int y = Find(parent,G->Edges[edges[i]].des);

        if (x==y)
            return true;
        Union(parent,x,y);
    }
    return false;
}


int* sort_edges(graph* my_graph)
{
    int temp[my_graph->E];
    int* index = (int*)malloc(my_graph->E*sizeof(int));

    for(int i=0;i<my_graph->E;i++){
        temp[i]=my_graph->Edges[i].weight;
        index[i] = i;
    }

    for(int i=0;i<my_graph->E-1;i++)
    {
        for (int j=i+1;j<my_graph->E;j++)
        {
            if(temp[i]>temp[j])
            {
                swap(temp[i],temp[j]);
                swap(index[i],index[j]);
            }
        }
    }
    return index;
}

void kruskal_algo(graph* G)
{
    int order[G->E];
    int edges[G->V-1];
    int i=0,j=0;
    int* a = sort_edges(G);

    for(int i=0;i<G->E;i++)
    {
        order[i] =*(a+i);
        //cout<<order[i]<<" ";
    }

    free(a);

    while(i<G->V-1)
    {
        //cout<<i<<" ";
        edges[i++] = order[j++];
        if (isCyclic(G,edges,i))
           i--;
    }
    cout<<"Edges included in Spanning Tree are : \n";
    for(int i=0;i<G->V-1;i++)
       cout<<G->Edges[edges[i]].src<<"-----"<<G->Edges[edges[i]].des<<" Cost of edge :"<<G->Edges[edges[i]].weight<<"\n";
}

int main()
{
    graph* my_graph = createGraph(9,14);

    my_graph->Edges[0].src = 0;
    my_graph->Edges[0].des = 1;
    my_graph->Edges[0].weight = 4;

    my_graph->Edges[1].src = 0;
    my_graph->Edges[1].des = 7;
    my_graph->Edges[1].weight = 8;

    my_graph->Edges[2].src = 1;
    my_graph->Edges[2].des = 7;
    my_graph->Edges[2].weight = 11;

    my_graph->Edges[3].src = 1;
    my_graph->Edges[3].des = 2;
    my_graph->Edges[3].weight = 8;

    my_graph->Edges[4].src = 7;
    my_graph->Edges[4].des = 6;
    my_graph->Edges[4].weight = 1;

    my_graph->Edges[5].src = 7;
    my_graph->Edges[5].des = 8;
    my_graph->Edges[5].weight = 7;

    my_graph->Edges[6].src = 2;
    my_graph->Edges[6].des = 8;
    my_graph->Edges[6].weight = 2;

    my_graph->Edges[7].src = 8;
    my_graph->Edges[7].des = 6;
    my_graph->Edges[7].weight = 6;

    my_graph->Edges[8].src = 2;
    my_graph->Edges[8].des = 3;
    my_graph->Edges[8].weight = 7;

    my_graph->Edges[9].src = 2;
    my_graph->Edges[9].des = 5;
    my_graph->Edges[9].weight = 4;

    my_graph->Edges[10].src = 6;
    my_graph->Edges[10].des = 5;
    my_graph->Edges[10].weight = 2;

    my_graph->Edges[11].src = 3;
    my_graph->Edges[11].des = 5;
    my_graph->Edges[11].weight = 14;

    my_graph->Edges[12].src = 3;
    my_graph->Edges[12].des = 4;
    my_graph->Edges[12].weight = 9;

    my_graph->Edges[13].src = 5;
    my_graph->Edges[13].des = 4;
    my_graph->Edges[13].weight = 10;

    kruskal_algo(my_graph);

    return 0;
}
