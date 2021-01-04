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

int height(n* pt)
{
    if(pt==NULL)
        return 0;
    else
    {
        int lh=height(pt->left);
        int rh=height(pt->right);
        return max((lh+1),(rh+1));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        add(&root,x);
    }

    cout<<height(root);

    return 0;
}

