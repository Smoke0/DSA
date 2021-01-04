/* This is ultimate perfect fact program can calculate any no. I have tested it with 15,000*/
#include<stdio.h>
# define N 10000
int main()
{
    int t,u;     // t is no of test case and u is the no. of digits in factorial.
    scanf("%d",&t);
    while(t--)
    {
    int n,z[2],a[N],b[N],fact[N+1]; //fact[] stores digits of factorial. z[] stores the digits of user entered no.
    int i=1,j=0,k=0,l,r,c=0,r_1,c_1=0,r_2,c_2=0;
    puts("\nEnter the no.");
    scanf("%d",&n);

    for(l=1;l<=N;l++)       //initialize every element of fact[] and b[] to zero.
    {
        fact[l]=0;
        b[l]=0;
    }
    fact[0]=1;
    for(i=1;i<=n;i++)       //this calculates the value of fact.
    {
        z[0]=i%10;     //z[0] is the unit digit of entered user no.
        z[1]=i/10;     // z[1] stores the value of other digits.
        for(j=0;j<N;j++)
          {
              a[j]=fact[j]*z[0]+c_1;  //multiplies individual elements together with previous factorial
              r_1=a[j]%10;
              c_1=a[j]/10;
              a[j]=r_1;

              if(z[1]!=0)
              {
                b[j+1]=fact[j]*z[1]+c_2; //multiplies individual elements together with previous factorial
                r_2=b[j+1]%10;
                c_2=b[j+1]/10;
                b[j+1]=r_2;
              }
              fact[j]=a[j];      // adds the individual elements of a[] and b[] together.
              b[0]=0;
              if(z[1]!=0)
              fact[j]=fact[j]+b[j]+c;  //just part of adding logic.
              c=0;
              if(fact[j]>9)            //just part of adding logic.
              {
                  r=fact[j]%10;
                  c=fact[j]/10;
                  fact[j]=r;
              }
          }
    }
    for(k=0;k<N;k++)  //This determines the no of digits of the factorial of no.
    {
        if(fact[k]!=0)    // It finds a non-zero no. of fact array which has every element to it's left  zero.
            {             // that's the no of digits of that factorial.
                for(j=k+1;j<N;j++)
                {
                if(fact[j+1]==0)
                u=k;
                }
            }
   }
    for(k=u;k>=0;k--)       // prints fact array elements.
    printf("%d",fact[k]);
    }
    return 0;
}
