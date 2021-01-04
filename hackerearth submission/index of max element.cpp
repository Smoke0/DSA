#include<iostream>

using namespace std;

int main()
{
    int arr[]={3,6,1,2,8};
    int max_index=0,k=arr[0];

    for(int i=1;i<5;i++)
    {
        if(k<arr[i])
        {
            max_index=i;
            k=arr[i];
        }
    }
    cout<<max_index;
}
