// this is standard implementation of bubble sort.
#include<iostream>

using namespace std;

void bubble_sort(int arr[],int n)
{
    int t;
    for(int i=0;i<n-1;i++)
    for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
}
int main()
{
    int a[5]={5,4,3,2,1};
    bubble_sort(a,5);
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";
}
