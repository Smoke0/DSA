#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *f,int *s)
{
    int t;
    t=*f;
    *f=*s;
    *s=t;
}

int part(int arr[],int start,int end)
{
    int i=start+1;
    srand((unsigned)time(0));
    int random=start+rand()%(end-start+1);
    swap(&arr[random],&arr[start]);
    int pivot=arr[start];
    for(int j=start+1;j<=end;j++)
    {
        if(arr[j]<pivot)
        {
            swap(&arr[i],&arr[j]);
            i+=1;
        }
    }
    swap(&arr[start],&arr[i-1]);

    return i-1;
}
void quick_sort(int arr[],int start, int end)
{
    if (start<end)
    {
        int pivot;
    pivot=part(arr,start,end);
    quick_sort(arr,start,pivot-1);
    quick_sort(arr,pivot+1,end);

    }

}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x,n;
        scanf("%d%d"&n,&x);
        int arr[n];
        for(int i=0;i<n;i++)
            scanf("%d"&arr[i]);
        quick_sort(arr,0,n-1);

        // counts distinct elements.
        int dis=1;
        int cur=arr[0];
        for(int i=1;i<n;i++)
        {
            if(cur!=arr[i])
            {
                dis++;
                cur=arr[i];
            }
        }
        if(dis==x)      puts("Good");
        else if(dis<x)  puts("Bad");
        else            puts("Average");
    }
}
