//This program finds the sum of two digits of range 10^99 each.
/*we give input as strings so this program takes two strings adds there's individual elements as there is no
limit for size of strings.*/
#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],b[100],sum[101],rev[100],big[100];                       //int storing arrays.
    int L_1,L_2,min,max;                                                //strings related integers
    int i,j,k;                                                          //counters
    int c=0,r=0;                     //c is carry on and r is remainder adding logic related ints.

    puts("Enter first digit");
    scanf("%s",a);

    puts("Enter second digit");
    scanf("%s",b);

    L_1=strlen(a);              /* this program takes a as large string and b as smaller one*/
    L_2=strlen(b);
    max=L_1>L_2?L_1:L_2;
    min=L_1<L_2?L_1:L_2;

    if(max==L_2)             // this block converts a into larger string if it wasn't.
    {
        strcpy(big,b);
        strcpy(b,a);
        strcpy(a,big);
    }

    L_1=strlen(a);             //these statements updates the value of string related ints.
    L_2=strlen(b);
    max=L_1>L_2?L_1:L_2;

    strcpy(rev,b);             // lines from 35 to 39 makes both stings of same size
    for(i=0;i<=max-1;i++)      // initialize every element of smaller string to zero
    b[i]='0';
    for(i=(max-min),j=0;i<max;i++,j++)
    b[i]=rev[j];                //puts elements of smaller string into string.

    for(i=L_1-1,j=L_1-1,k=0;i>=0,j>=0;i--,j--,k++)    // finally adds individual elements.
    {
        sum[k]=a[i]-48+b[j]-48+c;            //48 is subtracted to convert char 0 to int 0.
        c=0;                                 // resetting carry on to 0 and it's very imp.
        if(sum[k]>9)               // if sum of elements is more than 9 we need r and c.
        {
            r=(sum[k])%10;
            c=sum[k]/10;
            sum[k]=r;
        }
    }
    a[max]=c;                         //this prints the carry on left after for loop terminates and it's imp.
    if((a[0]-48+b[0]-48+c)>9)
    printf("%d",a[max]);
    for(i=max-1;i>=0;i--)           // finally prints the result.
    printf("%d",sum[i]);
    return 0;
}
