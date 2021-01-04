#include<stdio.h>
int main()
{
    long long int n,i,j,k=0,low,up,cur=0,pre=0;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        k=0;
        scanf("%lld",&n);
    for(i=1;i<=200000000;i++)
    {
        pre=cur;
        j=i-1;
        low=5*j;
        up=5*i;
        if(low<n&&n<up)
            cur=pre;
        else if(n>=up)
            {
                while(up)
                {
                    if(up%5==0)
                    {
                    k++;
                    up=up/5;
                    }
                    else
                        up=0;
                    cur=k;
                }
            }
    }
   printf("%lld\n",cur);
   cur=0;
   pre=0;
    }

    return 0;
}
