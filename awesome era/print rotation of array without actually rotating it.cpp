#include<iostream>
#include<unordered_map>
#include<iterator>
using namespace std;

/// this function rotates array by k in both left as well as right -ve value of k rotate array to left by k
/// +ve value rotatr array right by k.
void rotateArray(int *arr,int n,int k,unordered_map<int,int> &index){
    unordered_map<int,int> :: iterator it;
    /// rotate left
    if(k<0){
    k = abs(k);
    k = k%n;
    if(k==0)
        return;
    for(int i=0;i<n;i++){
        it = index.find(i);
        it->second = (it->second + k)%n;
    }
    /// rotate right
    }
    else{
    k = k%n;
    if(k==0)
        return;
    for(int i=0;i<n;i++){
        it = index.find(i);
        it->second = (it->second - k)%n;
        if(it->second <0)
            it->second +=n;
    }
    }
}
void printRotatedArray(int *arr,int n,unordered_map<int,int> &index){
    for(int i=0;i<n;i++){
        cout << arr[index[i]];
    }
}
int main(){
    int arr[] = {5,4,3,3,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    unordered_map<int,int> index;
    for(int i=0;i<5;i++)
        index[i] = i;

    rotateArray(arr,n,-1,index);
    rotateArray(arr,n,2,index);
    printRotatedArray(arr,n,index);

    return 0;
}
