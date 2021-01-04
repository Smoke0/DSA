# include<stdio.h>
int main()
{
    int n=0,i=0;
    scanf("%d",&n);
    long long int a[n],b[n];
    for(i=0;i<n;i++)
        scanf(" %lld",&a[i]);
    for(i=0;i<n;i++)
        scanf(" %lld",&b[i]);
    puts(a);
    puts(b);



return 0;
}
