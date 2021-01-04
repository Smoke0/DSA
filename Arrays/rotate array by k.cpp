#include<iostream>

using namespace std;

/// this function rotates array by k in both left as well as right -ve value of k rotate array to left by k
/// +ve value rotatr array right by k.
/// gfg verified.
void rotateArray(int *arr,int n,int k){
    /// rotate left
    if(k<0){
    k = abs(k);
    k = k%n;
    if(k==0)
        return;
    int temp[k];
    for(int i=0;i<k;i++)
        temp[i] = arr[i];
    for(int j = k;j<n;j++)
        arr[j-k] = arr[j];
    for(int i=n-k,j=0;i<n;i++,j++)
        arr[i] = temp[j];
    }
    /// rotate right
    else{
    k = k%n;
    if(k==0)
        return;
    int temp[k];
    /// store k elements
    for(int i=0,j=n-k;i<k;i++,j++){
        temp[i] = arr[j];
    }
    /// shift array to right by k.
    for(int i=n-k-1;i>=0;i--)
        arr[i+k] = arr[i];
    /// copy temp to array
    for(int i=0;i<k;i++)
        arr[i] = temp[i];
    }
}

int main(){

    return 0;
}
