#include<iostream>

using namespace std;

int b_search(int arr[],int n,int x)
{
    int sum=0;
    if(x>arr[n-1])
        {
            for(int i=0;i<n;i++)
                sum+=arr[i];
            cout<<n<<" "<<sum<<"\n";
        }
    int s=0,f=n,m;

    for(int i=0;i<n;i++)
    {
      m=(s+f)/2;
    if(arr[m]==x)
    {
        for(int i=0;i<=m;i++)
            sum+=arr[i];
        cout<<m+1<<" "<<sum<<"\n";
        break;
    }

    else if(arr[m]>x)
        f=m-1;

    else if(arr[m]<x)
        s=m+1;

    }
}

void counting_sort(int arr[],int n)
{
    int k=arr[0];

    for(int i=1;i<n;i++)
        k=max(k,arr[i]);

    int aux[k+1];

    for(int i=0;i<=k;i++)
        aux[i]=0;

    for(int j=0;j<n;j++)
        aux[arr[j]]++;

    int sorted[n];
    int i=0;

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
    int n,q,pow;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    counting_sort(arr,n);
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>pow;
        b_search(arr,n,pow);
    }
}
