// This program calculates no of zeros in fact of no. but it a slow program.
// It actually calculates no of 5 in fact as no of two is always greater than no of 5's.
#include<stdio.h>
int main()
{
    long long int n=1000000000,i,j,k=0;
    //scanf("%lld",&n);
    for(i=1;i<=n;i++)
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

    }
    printf("%lld",k);
    return 0;
}
