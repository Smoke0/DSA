#include<bits/stdc++.h>
#define N 100000

using namespace std;

int top = -1;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int my_stk[N];
    int m,counter=0;
    string str;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>str;
        for(int i=0;i<str.length();i++)
        {
            if(str[i]!=my_stk[top] || top==-1)
                my_stk[++top]=str[i];

            else
                top--;
        }
        if(top==-1)
            counter++;
        top=-1;
    }
        cout<<counter<<"\n";
}

