#include<iostream>

using namespace std;

void counting_sort(int arr[],int n)
{
    int k=arr[0];

    for(int i=1;i<n;i++)  // finds the key i.e. the max element of array.
        k=max(k,arr[i]);

    int aux[k+1];

    for(int i=0;i<=k;i++) // initialize every element of aux to zero.
        aux[i]=0;

    for(int j=0;j<n;j++)  // aux stores the frequency of each element.
        aux[arr[j]]++;

    int sorted[n];       // stores the sorted version of array.
    int i=0;             // index of sorted array.

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

}
int main()
{
    int a[6]={66,52,4,39,27,13};
    counting_sort(a,6);
    for(int i=0;i<6;i++)
        cout<<a[i]<<" ";
    return 0;
}
