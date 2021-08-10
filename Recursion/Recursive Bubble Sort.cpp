#include<iostream>

using namespace std;

void BubbleSort(int *arr,int n){
    /// base case
    /// if array has only one element it's sorted.
    if(n==1)
        return;

    /// I am putting the largest element in correct position for bigger array.
    for(int j=0;j<n-1;j++){
        if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
    }
    /// recursive case.
    /// recursion would do the job of putting largest element for smaller array.
    BubbleSort(arr,n-1);
}
void PrintArray(int *arr,int n){
    for(int i=0;i<n;i++){
        cout <<arr[i] <<" ";
    }
    cout <<"\n";
}
int main(){
    int arr[] = {9,8,7,6,5,4,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    PrintArray(arr,n);
    BubbleSort(arr,n);
    PrintArray(arr,n);
	return 0;
}
