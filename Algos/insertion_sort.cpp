#include<iostream>

using namespace std;

void insertion_sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int cur=arr[i];
        int j=i;
        while(j>0 && cur<arr[j-1])
        {
            arr[j]=arr[j-1];
            j-=1;
        }
        arr[j]=cur;
    }
}
int main()
{
    int a[7]={99,78,5,4,3,2,1};
    insertion_sort(a,7);
    for(int i=0;i<7;i++)
        cout<<a[i]<<" ";
}
