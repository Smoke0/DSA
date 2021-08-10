#include<iostream>

using namespace std;

int SumOfArray(int *arr,int n){
    /// base case
    if(n==1){
        return arr[0];
    }
    /// both works but in different direction.
    ///return arr[n-1] + SumOfArray(arr,n-1);
    return arr[0] + SumOfArray(arr+1,n-1);
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout <<SumOfArray(arr,n);
	return 0;
}
