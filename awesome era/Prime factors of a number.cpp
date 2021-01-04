#include <iostream>
#include<cmath>
#include<stack>
using namespace std;

void printPrimesFactors(int n){
    int largest;
    /// corner case.
    if(n==1)
        cout << "1 is neither prime nor composite\n";
    /// divide number and make it odd suck all 2 out of it.
    while(n%2==0){
        cout <<2 <<" ";
        n/=2;
    }
    /// now number must be odd and if it's composite we would find atlesat one prime factor less than sqrt(n).
    for(int i=3;i<=sqrt(n);i=i+2){
        while(n%i==0){
            cout << i << " ";
            n/=i;
        }
    }
    /// now n must be prime number or it might be one, if it's a prime print it.
    if(n>2){
        cout << n;
    }
}
int main() {
    int n;
    cin >> n;
    printPrimesFactors(n);
	return 0;
}
