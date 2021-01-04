int main()
{
    int t=0,len=0;
    scanf("%d",&t);
    while(t--)
    {
        int i=0,c=0;
        char str[100000];
        scanf("%s",str);
        len=strlen(str);
    for(i=0;i<len;i++)
    {
     if(str[i] == 'a' )
        c++;
    if(str[i] == 'e' )
        c++;
        if(str[i] == 'i' )
        c++;
        if(str[i] == 'o' )
        c++;
        if(str[i] == 'u' )
        c++;
        if(str[i] == 'A' )
        c++;
        if(str[i] == 'E' )
        c++;
        if(str[i] == 'I' )
        c++;
        if(str[i] == 'O' )
        c++;
        if(str[i] == 'U' )
        c++;
    }
    printf("%d\n",c);

    }
}
