# include<stdio.h>
int main()
{
    int n=0,i=0;
    scanf("%d",&n);
    long long int str[n];
    for(i=0;i<n;i++)
        scanf(" %lld",&str[i]);
    puts(str);

    return 0;
}
