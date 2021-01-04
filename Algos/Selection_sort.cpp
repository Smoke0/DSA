// it a standard selection sort can be improved by same method bubble sort improved.

#include<iostream>

using namespace std;

void selection_sort(int arr[],int n)
{
    int min,t;
    for(int i=0;i<n-1;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if (arr[j]<arr[min])
                min=j;
        }
        t=arr[min];
        arr[min]=arr[i];
        arr[i]=t;
    }
}
int main()
{
    int a[5]={5,4,6,2,1};
    selection_sort(a,5);
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";
}
