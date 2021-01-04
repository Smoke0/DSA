#include<iostream>
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
    do{
        r = divident%divisor;
        divident = divisor ;
        divisor = r;
   }while(remainder);
   return divident;

}
int main() {
   int n1,n2,remainder;
   long long int product;
   cin>>n1>>n2;
   product = (long long int)n1*n2;
   do{
        remainder = n2%n1;
        n2 = n1;
        n1 = remainder;
   }while(remainder);
   cout << product/n2;
	return 0;
}
