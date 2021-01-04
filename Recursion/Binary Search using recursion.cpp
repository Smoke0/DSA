#include<iostream>

using namespace std;

/// finds nth fibo no. starting with one.
void bs(int *arr,int s,int l,int x){
    /// base case
    if(s>l){
        cout <<"Key not found\n";
        return;
    }
    int mid = (s+l)/2;
    if(arr[mid]==x){
        cout << "Key found at index " <<mid <<"\n";
        return;
    }
    else if(arr[mid]>x){
        return bs(arr,s,mid-1,x);
    }
    else{
        return bs(arr,mid+1,l,x);
    }

}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key;
    cin >>key;
    bs(arr,0,n-1,key);
	return 0;
}
