#include<iostream>

using namespace std;

void subsets(int *arr,int *out,int n,int i,int j){
    /// base case
    if(n==0){
        for(int k=0;k<j;k++)
            cout << out[k];
        cout << "\n";
        return;
    }
    out[j] = arr[i];
    /// recursive case.
    subsets(arr,out,n-1,i+1,j+1);
    subsets(arr,out,n-1,i+1,j);
}

int main(){
    int arr[] = {1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int out[n];
    subsets(arr,out,n,0,0);
	return 0;
}
