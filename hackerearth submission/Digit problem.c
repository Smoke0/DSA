#include <stdio.h>

int main()
{
    char str[19];
    int k=0,i=0,j=0;
    scanf("%s %d",str,&k);
    for(i=0;i<k;i++)
    {
        if(str[i]!='9')
        str[i]='9';
        for(j=1;j<19-i;j++)
        else if(str[i+j]!='9')
            str[i+j]='9';

    }
    puts(str);
    return 0;
}
