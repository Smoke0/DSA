 #include<iostream>

using namespace std;

void Print(int n){
    /// base case
    if(n==0){
        return;
    }
    /// recursive case.
    Print(n-1);
    cout <<n <<"\n";
}
int main(){
    //int arr[] = {1,2,3,4,5,6,7,8,9};
    //int n = sizeof(arr)/sizeof(arr[0]);
    int n;
    cin >>n;
    Print(n);
	return 0;
}
