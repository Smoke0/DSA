#include<iostream>
#include<cstdlib>

using namespace std;
int height=0;
typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
}n;

n* root=NULL;

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
        if(x<(*rpt)->val)
            add(&(*rpt)->left,x);
        else
            add(&(*rpt)->right,x);
    }
}

void find_height(n** pt)
{

}

int main()
{
    add(&root,2);
    add(&root,1);
    add(&root,3);
    add(&root,4);
    find_height(&root);
    return 0;
}
