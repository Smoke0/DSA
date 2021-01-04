#include<iostream>
#include<cstdio>

using namespace std;

int i=0;
int swaps=0;

void fastscan(int &number)
{
    bool negative = false;
    register int c;

    number = 0;
    c = getchar();
    if (c=='-')
    {
        negative = true;

        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

    if (negative)
        number *= -1;
}

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
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    fastscan(n);
    int tree[n];
    int arr[n];
    for(int i=0;i<n;i++)
      fastscan(tree[i]);

    in_order(1,n,tree,arr);

    cout<<min_swaps(arr,0,n-1)<<"\n";

}
