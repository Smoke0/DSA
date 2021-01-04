#include <stdio.h>

int main()
{
    char str[100];
    int i=0,j=0,count_1=0,count_0=0;
    scanf("%s",str);
    for(i=0;i<100;i++)
    {
        if(str[i]=='1')
        {
            if(count_0<15)
            count_0=0;
            for(j=i+1;j<=i+5;j++)
            if(str[j]=='1')
            count_1++;
        }
      if(str[i]=='0')
        {
            if(count_1<15)
            count_1=0;
            for(j=i+1;j<=i+5;j++)
            if(str[j]=='0')
            count_0++;
        }
    }
        if(count_1>=15 || count_0>=15)
                printf("Sorry, sorry!");
                else
                printf("Good luck!");
    return 0;
}
