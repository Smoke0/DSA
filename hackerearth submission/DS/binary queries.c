int main()
{
  int n,q,i;
  int l,r,x;
  scanf("%d %d",&n,&q);
  int str[n],que[3];
  for(i=0;i<n;i++)
    scanf("%d",&str[i]);
  for(i=0;i<q;i++)
  {
      scanf("%s",que);
      printf("\n%s",que);
      if(strlen(que)==2)
        {
            x=que[1];
            printf("%d",x);
        }
    else
        l=que[1];r=que[2];

  }

}
