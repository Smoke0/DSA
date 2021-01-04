/// the idea is taken from gfg the idea is to use std::sort function. In our comparison function we
/// let's take an ex to understand numbers are 54 and 546 we form two numbers a_b and b_a which are
/// 54546 and 54654 now we compare them here as 54654 is larger we place 546 before 54 we do this for
/// all number to get the answer.
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int mycomp(int a,int b){
    int digits_a=0,digits_b=0;
    int a_copy = a,b_copy = b;
    long long int a_b,b_a;
    while(a_copy){
        digits_a++;
        a_copy/=10;
    }
    while(b_copy){
        digits_b++;
        b_copy/=10;
    }
    a_b = a*pow(10,digits_b) + b;
    b_a = b*pow(10,digits_a) + a;
    return a_b>b_a ? 1 : 0;
}
int main()
{
    int n,*arr,t,temp;
    cin>>t;
    while(t--){
        cin >> n;
        arr = (int*)malloc(n*sizeof(int));
        for(int i=0;i<n;i++){
            cin >> temp;
            *(arr+i) = temp;
        }
        sort(arr,arr+n,mycomp);
        for(int i=0;i<n;i++)
            cout << arr[i];
    }

}
