#include <iostream>
using namespace std;

int gcd(int a,int b){
    int divident,divisor,r;
    if(a>b){
        divident = a;
        divisor = b;
    }
    else{
        divident = b;
        divisor = a;
    }
    /// case when divisor is zero because gcd(k,0) = k; gcd(0,0) = undefined.
    if(!divisor)
        return divident;
    do{
        r = divident%divisor;
        divident = divisor ;
        divisor = r;
   }while(r);
   return divident;

}
int main() {
	int t,n,result;
	cin >>t;
	while(t--){
	    cin >> n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin >> arr[i];
	    result = arr[0];
	    for(int i=1;i<n;i++){
	        result = gcd(result,arr[i]);
	    }
	    cout << result <<"\n";
	}
	return 0;
}
