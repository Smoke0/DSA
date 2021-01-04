#include<iostream>

using namespace std;
int top=-1;
int h=-1;

int harry(int m_coins[],int h_coins[],int n,int x)
{
    int worth=0;
    top+=1;
    h+=1;
    m_coins[top]=h_coins[h];
    for(int i=0;i<top+1;i++)
        worth+=m_coins[i];
    if (worth==x)
        {
            cout<<(top+1)<<endl;
            return 1;
        }
    else
        return 0;
}

void rem(int m_coins[],int n)
{
    top-=1;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n,q,x,a=0;
    string str;
    cin>>n;
    int h_coins[n],m_coins[n];
    for(int i=0;i<n;i++)
        cin>>h_coins[i];
    cin>>q>>x;
    for(int i=0;i<q;i++)
        {
            cin>>str;
            if (str=="Harry")
                a=harry(m_coins,h_coins,n,x);
                if (a==1)
                    break;
            if (str=="Remove")
                rem(m_coins,n);

        }
        if (a==0)
            cout<<-1;

    return 0;
}
