#include<iostream>

using namespace std;

void swapping(int* a,int* b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
    int a=6,b=7;
    swapping(&a,&b);
    cout<<a<<b;
}
