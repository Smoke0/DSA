#include <iostream>
#include<cmath>
#include<stack>
using namespace std;

int main() {
    long long int n,k,t;
    cin >>t;
    while(t--){
    stack<long long int> s;
    cin >> n >>k;
    for(int i=1;i<=sqrt(n);i++){
    if(n%i==0){
        if(i==n/i){
            ///cout << i <<" ";
            if(k==1){
                cout << i <<"\n";
                k=0;
                break;
            }
            k--;
        }

        else{
            ///cout << i <<" ";
            if(k==1){
                cout << i <<"\n";
                k=0;
                break;
            }
            k--;
            s.push(n/i);
        }
    }
    }
    if(k>=1){
        while(!s.empty()){
        ///cout << s.top() <<" ";
        if(k==1){
                cout << s.top() <<"\n";
                k=0;
                break;
            }
            k--;
        s.pop();
        }
    }
    if(k>0)
        cout <<-1 <<"\n";
    while(!s.empty())
        s.pop();
    }
	return 0;
}
