# include<iostream>

using namespace std;

int top=-1;

void push(int stk[100000],int x)
{
    top+=1;
    stk[top]=x;
}

void pop(int stk[100000])
{
    stk[top-2]=stk[top];
    top-=1;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,ID;
        int stk[100000];
        char ch;
        cin>>n>>ID;
        push(stk,n);
        for(int i=0;i<n;i++)
        {
            cin>>ch;
            if(ch=='P')
            {
                cin>>ID;
                push(stk,ID);
            }

            //cout<<ch<<ID;
            else
                pop(stk);
        }
        cout<<"Player"<<stk[top];
    }
    return 0;
}
