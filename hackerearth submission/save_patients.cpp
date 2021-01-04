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
     int n,c=0;
     cin>>n;
     int vac[n],patient[n];
     for(int i=0;i<n;i++)
        cin>>vac[i];
     for(int i=0;i<n;i++)
        cin>>patient[i];

    bubble_sort(vac,n);
    bubble_sort(patient,n);

    for(int i=0;i<n;i++)
    {
        if(vac[i]>=patient[i])
            c++;
    }

        if(c==n)
            cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
 }
