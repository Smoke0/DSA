#include<stdio.h>

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

bool search_tree(n* rpt,int x)
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
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int cur;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&cur);
            add(&root,cur);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d",&cur);
            if(search_tree(root,cur)==1)
            {
                printf("Yes\n");
                add(&root,cur);
            }
            else
            {
                printf("NO\n");
                add(&root,cur);
            }
        }
        deletetree(&root);
    }
}
