#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,count=0;
        scanf("%d",&n);
        char str[n];
        scanf("%s",str);

        for(i=0;i<n;i++)
        {
            if(str[i-1]>= '0' && str[i-1]<= '9' && str[i]>= 'a' && str[i]<= 'z' || str[i]>= 'A' && str[i]<= 'Z')
            count++;
            if(str[n-1]>= '0' && str[n-1]<= '9')
            count++;
        }
            if(str[n-1]>= '0' && str[n-1]<= '9')
                count=count-n+1;
            printf("%d\n",count);
    }

    return 0;
}
