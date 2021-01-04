
#include<iostream>

using namespace std;

int bubble_sort(int arr[],int n)
{
    int t,swap=0;
    for(int i=0;i<n-1;i++)
    {
            for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
                swap++;
            }
        }
        }
    return swap;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<bubble_sort(arr,n);
}

