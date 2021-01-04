#include <iostream>
#include<climits>
using namespace std;

int main() {
	int n,max,max_2;
	int arr[] = {1,2,3,4,5};
	   max = arr[0];
	    for(int i=1;i<5;i++){
	        if(arr[i]>=max){
	            max_2 = max;
	            max = arr[i];
	        }
	        else if(arr[i]<max &&arr[i]>max_2){
	            max_2 = arr[i];
	        }
	    }
	    cout <<max << max_2 <<"\n";
	return 0;
}
