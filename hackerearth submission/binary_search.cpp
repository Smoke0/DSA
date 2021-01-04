#include<iostream>

using namespace std;

int b_search(int arr[],int n,int x)
{
    int s=0,f=n,m;

    for(int i=0;i<n;i++)
    {
      m=(s+f)/2;
    if(arr[m]==x)
    {
        return m+1;
        break;
    }

    else if(arr[m]>x)
        f=m-1;

    else if(arr[m]<x)
        s=m+1;

    }
    return -1;
}

int main()
{
    int ar[]={1,2,3,4,5,6,7};
    int n=sizeof(ar)/sizeof(ar[0]);
    cout<<b_search(ar,n,7);
}
