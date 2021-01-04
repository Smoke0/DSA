#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
}n;

n* root=NULL;

void delete_tree(n* node)
{
    if(node==NULL) return;

    delete_tree(node->left);
    delete_tree(node->right);

    free(node);
}

void deletetree(n** nod_ptr)
{
    delete_tree(*nod_ptr);
    *nod_ptr=NULL;
}


bool search_tree(n* rpt,int x)   // tell if there is an element present or not.
{
    if(rpt==NULL)
        return false;
    if(x==rpt->val)
        return true;

    if(x<(rpt->val))
       return search_tree((rpt->left),x);
    if (x>(rpt->val))
        return search_tree((rpt->right),x);

}

void add(n** rpt,int x)
{
    if(*rpt==NULL)
    {
        (*rpt)=(n*)malloc(sizeof(n));
        (*rpt)->val=x;
        (*rpt)->left=NULL;
        (*rpt)->right=NULL;
    }
    else
    {
        if(x<=(*rpt)->val)
            add(&(*rpt)->left,x);
        else
            add(&(*rpt)->right,x);
    }
}
int main()
{

}
