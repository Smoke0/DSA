# include<stdio.h>
int main()
{
    int n=0;
    scanf("%d",&n);
    while(n--)
    {
        int i=0,j=0,c=0;
        char str[4][4];
        for(i=0;i<=3;i++)
        scanf("\n%c%c%c%c",&str[i][0],&str[i][1],&str[i][2],&str[i][3]);


        for(i=0;i<=3;i++)
        {
            for(j=0;j<=3;j++)
            {
            // This will look for horizontal match.
            if(str[i][j]=='x' && str[i][j+1]=='x' && str[i][j+2]=='.' || str[i][j]=='x' && str[i][j+1]=='.' && str[i][j+2]=='x' || str[i][j]=='.' && str[i][j+1]=='x' && str[i][j+2]=='x')
                {
                    puts("YES");
                    i=4;
                    break;
                }
            // This will look for vertical match.
            else if(str[i][j]=='x' && str[i+1][j]=='x' && str[i+2][j]=='.' || str[i][j]=='x' && str[i+1][j]=='.' && str[i+2][j]=='x' || str[i][j]=='.' && str[i+1][j]=='x' && str[i+2][j]=='x')
                {

                    puts("YES");
                    i=4;
                    break;
                }
            // this one for  principal diagonal.
            else if(str[0][1]=='x' && str[1][2]=='x' && str[2][3]=='.' || str[0][1]=='x' && str[1][2]=='.' && str[2][3]=='x' || str[0][1]=='.' && str[1][2]=='x' && str[2][3]=='x')
                {
                   puts("YES");
                    i=4;
                    break;
                }
            else if(str[1][0]=='x' && str[2][1]=='x' && str[3][2]=='.' || str[1][0]=='x' && str[2][1]=='.' && str[3][2]=='x' || str[1][0]=='.' && str[2][1]=='x' && str[3][2]=='x')
                {
                   puts("YES");
                    i=4;
                    break;
                }
            else if(str[0][0]=='x' && str[1][1]=='x' && str[2][2]=='.' || str[0][0]=='x' && str[1][1]=='.' && str[2][2]=='x' || str[0][0]=='.' && str[1][1]=='x' && str[2][2]=='x')
                {
                   puts("YES");
                    i=4;
                    break;
                }
            else if(str[1][1]=='x' && str[2][2]=='x' && str[3][3]=='.' || str[1][1]=='x' && str[2][2]=='.' && str[3][3]=='x' || str[1][1]=='.' && str[2][2]=='x' && str[3][3]=='x')
                {
                   puts("YES");
                    i=4;
                    break;
                }

            // this one for  other diagonal.
            else if(str[0][2]=='x' && str[1][1]=='x' && str[2][0]=='.' || str[0][2]=='x' && str[1][1]=='.' && str[2][0]=='x' || str[0][2]=='.' && str[1][1]=='x' && str[2][0]=='x')
                {
                    puts("YES");
                    i=4;
                    break;
                }
                else if(str[1][3]=='x' && str[2][2]=='x' && str[3][1]=='.' || str[1][3]=='x' && str[2][2]=='.' && str[3][1]=='x' || str[1][3]=='.' && str[2][2]=='x' && str[3][1]=='x')
                {
                    puts("YES");
                    i=4;
                    break;
                }
                else if(str[0][3]=='x' && str[1][2]=='x' && str[2][1]=='.' || str[0][3]=='x' && str[1][2]=='.' && str[2][1]=='x' || str[0][3]=='.' && str[1][2]=='x' && str[2][1]=='x')
                {
                    puts("YES");
                    i=4;
                    break;
                }
                else if(str[1][2]=='x' && str[2][1]=='x' && str[3][0]=='.' || str[1][2]=='x' && str[2][1]=='.' && str[3][0]=='x' || str[1][2]=='.' && str[2][1]=='x' && str[3][0]=='x')
                {
                    puts("YES");
                    i=4;
                    break;
                }

            }
        }
        if(i!=5)
            puts("NO");
    }
            return 0;
}
