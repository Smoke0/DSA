///this is wrong implementation.
#include<iostream>

using namespace std;

void counting_sort(int arr[],int n)
{
    int k=arr[0];

    for(int i=1;i<n;i++)  /// finds the key i.e. the max element of array.
        k=max(k,arr[i]);

    int aux[k+1];

    for(int i=0;i<=k;i++) /// initialize every element of aux to zero.
        aux[i]=0;

    for(int j=0;j<n;j++)  /// aux stores the frequency of each element.
        aux[arr[j]]++;

    int sorted[n];       /// stores the sorted version of array.
    int i=0;             /// index of sorted array.

    for(int j=0;j<=k;j++)
    {
        int occ=aux[j];
        while(occ--)
        {
            sorted[i]=j;
            arr[i]=sorted[i];
            i++;
        }
    }
    cout << "The pass array is\n";
    for(int i=0;i<n;i++){
        cout << arr[i] <<" ";
    }
    cout << "\n";
}

void radix_sort(int arr[],int n)
{
    int pass[n],x=10;
    int k=arr[0];

    for(int i=1;i<n;i++)  /// finds the key i.e. the max element of array.
        k=max(k,arr[i]);

    while(k!=0)
    {
        for(int i=0;i<n;i++)
            pass[i]=arr[i]%x;
        counting_sort(pass,n);
        x*=10;
        k=k/10;
    }
    for (int i=0;i<n;i++)
        arr[i]=pass[i];
}

int main()
{
    int a[]={10,21,17,34,44,11,654,123};
    int n=sizeof(a)/sizeof(a[0]);
    radix_sort(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
