#include<iostream>

using namespace std;

void a_c(int a,string str,int n)
{
    int c;
    for(int i=a+2;i<n-1;i++)
    {
        if(str[a]==str[i])
            {
                c=i;
                b_d(a,c,str,n);
                break;
            }
    }
}

void b_d(int a,int c,string str,int n)
{
    for(int b=a+1;b<n-2;b++)
    {

    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    string str;
    cin>>n;
    cin>>str;
    int a=0,b=1,c=2,d=3;
    for(a=0;a<n-3;a++)
    {
        a_c(a,str,n);
    }


}
