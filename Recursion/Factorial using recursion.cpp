#include<iostream>

using namespace std;

long long fact(int n){
    /// base case
    if(n==0)
        return 1;

    ///recursive case
    return n*fact(n-1);
}
int main(){
    int n;
    cin >>n;
    cout << fact(n);
	return 0;
}
