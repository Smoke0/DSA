#include<iostream>

using namespace std;

/// finds nth fibo no. starting with one.
long long fibonacci(int n){
    /// base case
    if(n==0 || n==1)
        return n;

    ///recursive case
    /// nth fibonnaci no is sum of n-1 th and n-2 th fibo no.
    return fibonacci(n-1) + fibonacci(n-2);
}
int main(){
    int n;
    cin >>n;
    cout << fibonacci(n);
	return 0;
}
