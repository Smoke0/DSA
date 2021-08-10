#include<iostream>

using namespace std;

bool isSorted(int *arr,int n){
    /// base case
    if(n==1)
        return 1;

    /// recursive case.
    /// smaller array is sorted and I just compare the first two elements of bigger array.
    if(isSorted(arr+1,n-1) && arr[0] <= arr[1])
        return 1;
    else
        return 0;
}
int main(){
    int arr[] = {1,2,3,5,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << isSorted(arr,n);
	return 0;
}
