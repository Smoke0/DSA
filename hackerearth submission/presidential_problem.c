int main()
{
    int t=0;
    scanf("%d",&t);
    while(t--)
    {
        int n=0,q=0,l=0,r=0,i=0,j=0;
        char str[20001];
        scanf("%d %d",&n,&q);
        scanf("%s",str);
        /*  operation on strings starts  here*/
        for(i=0;i<q;i++)
        {
            scanf("%d %d",&l,&r);
            for(j=l-1;j<=r-1;j++)
            {
                str[j]=str[j]-1;
                if(str[j]>'z')
                    str[j]=str[j]-26;
                if(str[j]<'a')
                    str[j]=str[j]+26;
            }
        }
            puts(str);
    }

}
