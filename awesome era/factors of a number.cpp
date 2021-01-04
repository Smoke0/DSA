#include <iostream>
#include<cmath>
#include<stack>
using namespace std;

int main() {
    long long int n,k,t;
    stack<long long int> s;
    cin >> n;
    for(int i=1;i<=sqrt(n);i++){
    if(n%i==0){
        if(i==n/i){
            cout << i <<" ";
        }

        else{
            cout << i <<" ";
            s.push(n/i);
        }
    }
    }
        while(!s.empty()){
        cout << s.top() <<" ";
        s.pop();
        }
	return 0;
}
