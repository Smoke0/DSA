#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
}n;

n* root=NULL;

void seeds(n** rpt)
{
        (*rpt)=(n*)malloc(sizeof(n));
        (*rpt)->val=1;
        (*rpt)->left=NULL;
        (*rpt)->right=NULL;
}



void add_node(n** rpt,int parent_node,int child, char side)
{
    if((*rpt)->val==parent_node)
    {

    }
    else
        add_node()
}
