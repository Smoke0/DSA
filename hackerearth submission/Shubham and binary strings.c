int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n=0,c=0,i;
        scanf("%d",&n);
        char str[n];
        scanf("%s",str);
        puts(str);
        for(i=0;i<n;i++)
        {
            if(str[i]=='0')
                c++;
        }
        printf("%d",c);
    }
}
