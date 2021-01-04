// code works fine but the name of file has problems.
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,i,m;
        scanf("%d %d",&n,&k);
        int str[n];
        for(i=0;i<n;i++)
            {
                scanf(" %d",&str[i]);

            }
        m=str[0];
        for(i=0;i<n;i++)
            {
                if(m>str[i])
                    m=str[i];
            }
        if(k>=m)
        printf("%d\n",k-m);
        else
            printf("%d",0);

    }



return 0;
}
