/// this implementation is verified using geeks for geeks.
#include <iostream>
#include<string>
#include<algorithm>
#include<sstream>

using namespace std;

void merge_util(int *arr,int l,int m,int r){
    int left[m-l+1],right[r-m];
    for(int i=0,j=l;j<=m;i++,j++)
        left[i] = arr[j];
    for(int i=0,j=m+1;j<=r;i++,j++)
        right[i] = arr[j];

    int i=0,j=0,k=l;
    while(i<m-l+1 && j<r-m){

        if(left[i]<right[j]){
            arr[k++]=left[i++];
        }
        else{
            arr[k++]=right[j++];
        }
    }
    while(i<m-l+1){
        arr[k++] = left[i++];
    }
    while(j<r-m){
        arr[k++]=right[j++];
    }
}
void mergeSort(int *arr,int l,int r){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge_util(arr,l,m,r);
    }

}
int main() {
    int arr[] = {9,8,7,6,5,4,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout << arr[i] <<" ";
	return 0;
}
