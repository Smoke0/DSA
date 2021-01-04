#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int x,n;
        cin>>n>>x;
        set <int> dis;
        int cur;
        for(int i=0;i<n;i++)
        {
            cin>>cur;
            dis.insert(cur);
        }
        if(dis.size()==x)      cout<<"Good\n";
        else if(dis.size()<x)  cout<<"Bad\n";
        else            cout<<"Average\n";
    }
}
