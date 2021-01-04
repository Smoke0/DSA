#include<iostream>

using namespace std;

int primetest(int N)
{
    for(int i=2;i*i<=N;i++)
    {
        if(N%i==0)
         return 0;
    }
    return 1;
}
int main()
{
    int a;
    a=primetest(96);
    cout<<a<<endl;
}
