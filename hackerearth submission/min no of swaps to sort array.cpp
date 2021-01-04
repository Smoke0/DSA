#include<iostream>

using namespace std;
int swaps=0;
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
        swap(arr[r],arr[max_index]);

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
        swap(arr[l],arr[min_index]);
        min_swaps(arr,l+1,r-1);
    }
    return swaps;
}

int main()
{
    int arr[]={4,5,2,1,5};
    cout<<min_swaps(arr,0,4);
    //for (int i=0;i<5;i++)
        //cout<<arr[i]<<" ";
}
