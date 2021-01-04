#include<stdio.h>
# define N 400005
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,i,j,k=0,zeros;
        int num[5];
        int c=0,p;
        scanf("%lld",&zeros);
        for(i=1;i<=N;i++)
        {
            j=i;   // j is the no to be tested for if it's divisible by 5.
            while(j)
            {
                if(j%5==0) // processes no only if it's divisible by 5.
                {
                    k++;  // k is the total no of fives in factorial.
                    j=j/5;
                }
                else
                j=0;
            }

            if(k==zeros)
            {
                num[c]=i;
                c++;
            }
            if(k>zeros)
            break;
        }
        printf("\n%d\n",c);
        for(p=0;p<c;p++)
            printf("%d ",num[p]);
    }

    return 0;
}
