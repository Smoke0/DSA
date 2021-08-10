// this is standard implementation of bubble sort.
// well it's kind of improved cause it has fewer iteration in av. case.
#include<iostream>

using namespace std;

void bubble_sort(int arr[],int n)
{
    int t,swap=0;
    for(int i=0;i<n-1;i++){
        swap=0;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
                swap++;
            }
        }
        if(swap==0)
            break;
    }
}
int main()
{
    int a[]={2,1,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    bubble_sort(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
