/// this is a standard implementation of quick sort. which chooses a random no as it's pivot.

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int part(int arr[],int start,int end){

    int i=start+1;
    srand((unsigned)time(0));
    int random=start+rand()%(end-start+1);
    //cout<<random<<endl;
    swap(arr[random],arr[start]);
    int pivot=arr[start];

    for(int j=start+1;j<=end;j++){
        if(arr[j]<pivot){
            swap(arr[i],arr[j]);
            i++;
        }
    }

    swap(arr[start],arr[i-1]);

    return i-1;
}
void quick_sort(int arr[],int start, int end){
    if (start<end){
        int pivot =part(arr,start,end);
        quick_sort(arr,start,pivot-1);
        quick_sort(arr,pivot+1,end);
    }
}

int main(){

    int ar[]={786,67,545,4345,334,234,13};
    int n=sizeof(ar)/sizeof(ar[0]);
    quick_sort(ar,0,n-1);

    return 0;
}
