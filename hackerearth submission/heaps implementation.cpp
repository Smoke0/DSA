#include<iostream>

using namespace std;

/*typedef struct heaps
{
    unsigned int size;
    int* arr;
}h;

void creatheap(unsigned int size)
{
    h* heap=(h*)malloc(sizeof(h));
    heap->size=size;
    heap->arr=(int*)malloc(size*sizeof(int));
}*/


void max_heapify(int arr[], int i,int n)
{
    int large;
    int l=2*i+1;
    int r=l+1;

    if(l<=n && arr[l]>arr[i])
        large=l;
    else
        large=i;

    if(r<=n && arr[r]>arr[large])
            large=r;

    if(large!=i)
    {
        swap(arr[i],arr[large]);
        max_heapify(arr,large,n);
    }
}

void creat_max_heap(int arr[],int n)
{
    for(int i=n/2;i>=0;i--)
        max_heapify(arr,i,n);
}

void heap_sort(int arr[], int n,int t)  // the swap
{
    creat_max_heap(arr,n-1);
    for (int i=n-1;i>0;i--)
    {
        int temp;
        for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
        cout<<endl;
        cout<<i<<endl;
        swap(arr[0],arr[i]);
        n--;
        max_heapify(arr,0,n);
    }
}

int main()
{
    int ar[]={4,1,3,2,16,9,10,14,8,7};
    int n=(sizeof(ar))/sizeof(ar[0]);

    //creat_max_heap(ar,n-1);
    heap_sort(ar,n,n);

    for(int i=0;i<n;i++)
        cout<<ar[i]<<" ";
}
