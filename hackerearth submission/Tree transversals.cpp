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

void inorder(n* root)   // this fn works perfectly fine.
{
    if(root->left!=NULL)
    {
            inorder(root->left);
            cout<<root->val<<" ";
            inorder(root->right);
    }
    else
        cout<<root->val<<" ";

}

int main()
{

}
