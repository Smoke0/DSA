#include<stdio.h>

int i=0;
int swaps=0;

void swapping(int* a,int* b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void in_order(int index,int n,int tree[],int arr[])
{
    if(index>n)
        return;
    in_order(index*2,n,tree,arr);
    arr[i++]=tree[index-1];
    in_order(index*2+1,n,tree,arr);
}

int min_swaps(int arr [], int l,int r)
{
    int min_index,max_index,k;
    if(l<r)
    {
        max_index=l;
        k=arr[l];

        for(int i=l+1;i<=r;i++)
        {
            if(k<arr[i])
            {
                max_index=i;
                k=arr[i];
            }
        }

        if(max_index!=r)
            swaps++;
        swapping(&arr[r],&arr[max_index]);

        min_index=l;
        k=arr[l];

        for(int i=l+1;i<=r;i++)
        {
            if(k>arr[i])
            {
                min_index=i;
                k=arr[i];
            }
        }

        if(min_index!=l)
            swaps++;
        swapping(&arr[l],&arr[min_index]);
        min_swaps(arr,l+1,r-1);
    }
    return swaps;
}

int main()
{
    int n;
    scanf("%d",&n);
    int tree[n];
    int arr[n];
    for(int i=0;i<n;i++)
      scanf("%d",&tree[i]);

    in_order(1,n,tree,arr);

    printf("%d\n",min_swaps(arr,0,n-1));
}
