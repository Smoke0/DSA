# include<stdio.h>
int main()
{
    int n=0;
    scanf("%d",&n);
    while(n--)
    {
        unsigned char str[100000];
        scanf("%s",str);
        int len,i;
        len=strlen(str);
        if(len%2==0)
        {
            for(i=0;i<len/2;i++)
            {
                str[i]=str[i]+str[len-1-i]-96;
                if(str[i]>122)
                str[i]=str[i]-26;
                str[len-1-i]=str[i];
            }
        }
       else
        {
                for(i=0;i<len/2;i++)
            {
                str[i]=str[i]+str[len-1-i]-96;
                if(str[i]>122)
                str[i]=str[i]-26;
                str[len-1-i]=str[i];
            }
            str[len/2]=str[len/2]*2-96;
            if(str[len/2]>122)
                    str[len/2]=str[len/2]-26;
        }

        puts(str);

    }
}
