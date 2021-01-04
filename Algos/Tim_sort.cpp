// Tim sort is sorting algo used in Java and python library
// this algo first perform insertion sort on sub arrays of size RUN(defined by programmer we are taking it 32 here).
// then we merge these sorted sub arrays using merge function of sort.
#include<iostream>
#define RUN 32
using namespace std;

void insertionsort(int arr[],int left,int right) // this performs insertion of sub arrays of size RUN.
{
    for(int i=left+1;i<=right;i++)
    {
        int cur=arr[i];
        int j=i-1;
        while(arr[j]>cur && j>=left)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=cur;
    }
}

// merging fn which merges the sorted sub arrays.
void merge(int arr[], int l,int m,int r)
{
    int len1=m-l+1,len2=r-m;
    int left[len1],right[len2];  // creates two temp half arrays.

    for(int i=0;i<len1;i++)
        left[i]=arr[l+i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < len1 && j < len2)  // this loop compares and merges the elements of two half array.
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // copy remaining elements of left, if any
    while (i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }

    // copy remaining element of right, if any
    while (j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}
void tim_sort(int arr[],int n)   // performs tim_sort on array.
{
    for(int i=0;i<n;i+=RUN)      // calls insertion sort for sub arrays of size RUN.
        insertionsort(arr, i, min((i+31), (n-1)));
     for (int size = RUN; size < n; size = 2*size)  // calls the merge sort with proper parameters.
    {
        for (int left = 0; left < n; left += 2*size)
        {
            int mid = left + size - 1;
            int right = min((left + 2*size - 1), (n-1));
            merge(arr,left,mid,right);
        }
    }
}

int main()
{
    int arr[] = {5,55,77,88, 21, 7, 23, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    tim_sort(arr, n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
