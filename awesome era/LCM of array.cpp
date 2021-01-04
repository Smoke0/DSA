/// this approach isn't suitable for finding LCM where array is large in size because LCM could be
/// larger than what long int can store so also modulo woun't help either check geeksforgeeks for reason
/// for finding modulo of larger number we would have to use factorization method.
#include <bits/stdc++.h>
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
    /// case when divisor is zero because gcd(k,0) = k;
    if(!divisor)
        return divident;
    do{
        r = divident%divisor;
        divident = divisor ;
        divisor = r;
   }while(r);
   return divident;

}
int main()
{
    int t,n;
    long long int result;
    cin >> n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin >> arr[i];
	    result = arr[0];
	    for(int i=1;i<n;i++){
	        result = (long long int)(result*arr[i])/gcd(result,arr[i]);
	    }
	    cout << result <<"\n";
    return 0;
}
