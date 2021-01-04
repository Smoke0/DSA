/// this program finds the perfect squares b/w a given range a,b both inclusive.
/// just look at formula you would get what it's doing also perfect squares are only no having odd factors.
#include <iostream>
#include<cmath>
using namespace std;

int main() {
	int t,a,b;
	cin >> t;
	while(t--){
	    cin >>a >>b;
	    cout << floor(sqrt(b)) - ceil(sqrt(a)) +1 <<"\n";
	}
	return 0;
}
