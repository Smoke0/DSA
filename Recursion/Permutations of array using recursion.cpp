#include<iostream>
#include<cstring>
using namespace std;

void Permutations(char *arr,int n,int i){
    if(i==n){
        for(int i=0;i<n;i++)
            cout << arr[i];
        cout <<"\n";
        return;
    }
    for(int j=i;j<n;j++){
        swap(arr[i],arr[j]);
        Permutations(arr,n,i+1);
        swap(arr[i],arr[j]);
    }
}

int main(){
    char arr[5] = "abc";
    Permutations(arr,strlen(arr),0);
	return 0;
}
