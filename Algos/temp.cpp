#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    int a=0;
    srand((unsigned)time(0));
    for(int i=0;i<10;i++)
    {a=rand()%5;
    cout<<a<<endl;
    }
}
