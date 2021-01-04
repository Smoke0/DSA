# include<iostream>

using namespace std;

int main()
{
    int n,q,x,r;
    cin>>n>>q;
    int str[n],que[3];
    for(int i=0;i<n;i++)
        cin>>str[i];
    for(int i=0;i<q;i++)
    {
        for(int j=0;j<3;j++)
           cin>>que[j];

             if (que[0]==0)
             {
                r=que[2];
                cout<<r<<endl;
                if(str[r-1]==1)
                    cout<<"ODD";
                if(str[r-1]==0)
                    cout<<"EVEN";
             }
             if (que[0]==1)
             {
                 x=que[1];
                 cout<<x<<endl;
             }
    }


    return 0;
}
