int main()
{
    int n=0,i=0,j=0,a=0;
    scanf("%d",&n);
    /* determination of prime no.*/
    for(i=2;i<=n;i++)
    {
        if(i==2)
            printf("%d ",i);
        for(j=2;j<=i-1;j++)
        {
            if(i%j==0)
            {
                break;
            }
            if(j==i-1)
                printf("%d ",i);

        }
    }
}
