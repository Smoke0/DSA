#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>

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

void print_stack_rev(stk* Stack)
{
    for(int i=Stack->top;i>=0;i--)
        cout<<Stack->arr[i]<<" ";
}

typedef struct Queue
{
    int front,rear,size;
    unsigned int capacity;
    int *arr;
}que;

que* create_queue(unsigned int capacity)
{
    que* Queue=(que*)malloc(sizeof(que));
    Queue->capacity=capacity;
    Queue->front=0;
    Queue->rear=0;
    Queue->size=0;
    Queue->arr=(int*)malloc(capacity*sizeof(int));
    return Queue;
}

void enqueue(que* Queue,int val)
{
    if(Queue->size==Queue->capacity)
        cout<<"Queue is full\n";
    else
    {
        Queue->size++;
        Queue->arr[Queue->rear++]=val;
    }
}

int dequeue(que* Queue)
{
    if(Queue->size==0)
        cout<<"Empty queue\n";
    else
    {
        Queue->size--;
        Queue->front++;
        return Queue->arr[Queue->front-1];
    }
}

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

void bfs(g* graph, int start)  // there is a problem in computing the level of tree.
{
    cout<<start<<" ";
    int u,lev=0;
    bool visited[graph->v];   // a array of visited elements.

    for (int i=0;i<graph->v;i++)    // marking that none element has been visited.
         visited[i]=false;

    vector <int> level(graph->v+1);   // a vector for keeping track of level of nodes.
    que* my_queue = create_queue(graph->v);  // a queue keeping the node which will be visited.

    enqueue(my_queue,start);
    visited[start]=1;
    level[start]=lev;

    while(my_queue->size!=0)   // this loop iterate through the graph.
    {
        u=dequeue(my_queue);
        n* cur=graph->arr[u].head;   // cur stores the pointer to the adj list

        if(cur!=NULL)
          lev++;

        cout<<"\nlevel is "<<lev<<endl;
        while(cur!=NULL)                 // this loop visits every element of adj list.
        {
            if(visited[cur->val]==0)
            {
                cout<<cur->val<<" ";
                visited[cur->val]=1;
                level[cur->val]=lev;
                enqueue(my_queue,cur->val);
            }
            cur=cur->next;
        }

    }
}

void dfs_visit(g* graph, int v, bool visited []) // this is correct but may seem weird due to directed graph.
{
    if(visited[v]==0)   // prints the visited element.
        cout<<v<<" ";
    visited[v]=1;

    n* cur=graph->arr[v].head;

    while(cur!=NULL)       // loop visits element of adj list.
    {
        if(visited[cur->val]==0)
            {
                cout<<cur->val<<" ";
                visited[cur->val]=1;
                dfs_visit(graph,cur->val,visited);
            }
            cur=cur->next;
    }
}

void dfs(g* graph)
{
   bool visited[graph->v];

   for (int i=0;i<graph->v;i++)
         visited[i]=false;

    for(int i=0;i<graph->v;i++)
        if(visited[i]==false)
            dfs_visit(graph,i,visited);

}

void topo_visit(g* graph,int i, bool visited[], stk* stack)
{
    visited[i]=true;

    n* cur=graph->arr[i].head;

    while(cur!=NULL)
    {
        if(visited[cur->val]==false)
            topo_visit(graph,cur->val,visited,stack);
        cur=cur->next;
    }
    push(stack,i);
}

void topo_sort(g* graph)
{

    stk* my_stack=creat_stack(graph->v);

    bool visited[graph->v];

    for (int i=0;i<graph->v;i++)
         visited[i]=false;

    for(int i=0;i<graph->v;i++)
        if(visited[i]==false)
            topo_visit(graph,i,visited,my_stack);

    cout<<"----------The Topological sort for graph is---------\n";
    print_stack_rev(my_stack);
}

bool cycle_util(g* graph, int v, bool visited [],bool recStack[]) // this finds out the cycle in directed graph.
    {
        cout<<v<<"\n";
        visited[v]=true;
        recStack[v]=true;

        n* cur=graph->arr[v].head;

        while(cur!=NULL)       // loop visits element of adj list.
        {
            if(visited[cur->val]==0)
            {
                visited[cur->val]=true;
                cout<<"The value of v "<<v<<" The value of adj list :"<<cur->val<<"\n";
                cycle_util(graph,cur->val,visited,recStack);
            }
            if(visited[cur->val]==1 && recStack[cur->val]==1)
                    return true;
            cur=cur->next;
        }
        recStack[v]=false;
        return false;

}

bool isCyclic(g* graph)
{
   bool visited[graph->v];
   bool recStack[graph->v];

   for (int i=0;i<graph->v;i++){
       visited[i]=false;
       recStack[i]=false;
   }

    for(int i=0;i<graph->v;i++){
       //cout<<"The value of i :"<<i<<" \n";
       if(visited[i]==false){
                if(cycle_util(graph,i,visited,recStack))
                return true;
        }
    }
    return false;
}

bool cycle_util_un(g* graph, int v, bool visited [],int parent)
{
    visited[v] = true;

    n* cur=graph->arr[v].head;

    while(cur!=NULL)       // loop visits element of adj list.
        {
            if(visited[cur->val]==0)
            {
                visited[cur->val]=true;
                //cout<<"The value of v "<<v<<" The value of adj list :"<<cur->val<<"\n";
                if(cycle_util_un(graph,cur->val,visited,v))
                    return true;
            }

            else if(cur->val != parent)
                return true;

            cur=cur->next;
        }
        return false;
}

bool isCyclic_undirected(g* graph)
{
    bool visited[graph->v];

    for (int i=0;i<graph->v;i++)
       visited[i]=false;

    for(int i=0;i<graph->v;i++){
       //cout<<"The value of i :"<<i<<" \n";
       if(visited[i]==false){
                if(cycle_util_un(graph,i,visited,-1))
                return true;
        }
    }
}

int main()
{
  g* my_graph=createGraph(5);
    addEdge(my_graph,0,1);
    addEdge(my_graph,1,0);
    addEdge(my_graph,2,1);
    addEdge(my_graph,1,2);
    addEdge(my_graph,0,3);
    addEdge(my_graph,3,0);
    addEdge(my_graph,3,2);
    addEdge(my_graph,2,3);
   //addEdge(my_graph,3,3);
    //addEdge(my_graph,3,5);
    //addEdge(my_graph,4,5);

  // bfs(my_graph,5);
  // dfs(my_graph);
  // cout<<" The returned value is\n"<<isCyclic(my_graph);
  // topo_sort(my_graph);
     cout<<isCyclic_undirected(my_graph);
}
