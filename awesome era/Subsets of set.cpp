/// Documentation.
/// This  programs finds factorial, nCr and all the subsets of a set with r elements

#include<iostream>
using namespace std;

int fact(int n)
{
    int res = 1;
    while(n!=1){
        res = res*n;
        n--;
    }
    return res;
}

int nCr(int n, int r)
{
    return fact(n)/(fact(r)*fact(n-r));
}

void util(int arr[], bool set[], int start, int last,int r, int count=0)
{
    bool temp[last+1];
    for (int i=0;i<=last;i++)
        temp[i]  = set[i];

    if (count!=r-1){
        temp[start] = 1;
        util(arr,temp,start+1,last,r,count+1);
    }

    if (count==r-1){
        temp[start] = 1;
            count++;
        int k = start;

        while (k<last+1){
            if (count==r){
                for (int j=0;j<=last;j++){
                    if(temp[j]==1)
                    cout<<arr[j]<<" ";
                }
                cout<<" \n";
                swap(temp[k],temp[k+1]);
                k++;
            }
        }
        return;
    }
    if (start<last)
        util(arr,set,start+1,last,r,count);
}

void subsets(int arr[], int n, int r)
{
    bool set[n];

    for (int i=0;i<n;i++)
        set[i] = false;

    util(arr,set,0,n-1,r);
}

int main()
{
    int arr[] = {1,4,3,2};
    int n = sizeof(arr)/sizeof(int);
    subsets(arr,n,2);
    return 0;
}


