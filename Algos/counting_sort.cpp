#include<iostream>

using namespace std;

void counting_sort(int arr[],int n)
{
    int k=arr[0];

    for(int i=1;i<n;i++)  /// finds the key i.e. the max element of array.
        k=max(k,arr[i]);

    int aux[k+1] = {0};  /// initialize every element of aux to zero.

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

}
int main()
{
    int a[]={66,52,4,39,5,27,13};
    int n=sizeof(a)/sizeof(a[0]);
    counting_sort(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
