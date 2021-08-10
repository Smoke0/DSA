#include<bits/stdc++.h>
using namespace std;

/// it's little complicated needed to be explained start and end are starting and ending index
int part(int arr[],int start,int end)
{
    /// what we do we choose a value as 'pivot' and put the pivot element in starting or
    /// ending (here in starting) i here is the index where we put the next element smaller than
    /// pivot

    int pivot=arr[start]; int i=start+1;

    /// j is iterator that iterate over array except the pivot that's why j starts with start+1
    for(int j=start+1;j<=end;j++)
    {
        if(arr[j]<pivot)
        {
            swap(arr[i],arr[j]);
            i+=1;
        }
    }
    /// now i must be pointing to next position to put the element smaller than pivot, i-1 already
    /// has a element smaller than pivot so we swap pivot element arr[start] with i-1 placing pivot
    /// in right position
    swap(arr[start],arr[i-1]);

    return i-1;
}
/// gfg verified
void quick_sort(int arr[],int start, int end)
{
    if (start<end){
        int pivot;
        pivot=part(arr,start,end);
        quick_sort(arr,start,pivot-1);
        quick_sort(arr,pivot+1,end);
    }

}

void merge_util(int *arr,int l,int m,int r){
    int left[m-l+1],right[r-m];
    for(int i=0,j=l;j<=m;i++,j++)
        left[i] = arr[j];
    for(int i=0,j=m+1;j<=r;i++,j++)
        right[i] = arr[j];

    int i=0,j=0,k=l;
    while(i<m-l+1 && j<r-m){

        if(left[i]<right[j]){
            arr[k++]=left[i++];
        }
        else{
            arr[k++]=right[j++];
        }
    }
    while(i<m-l+1){
        arr[k++] = left[i++];
    }
    while(j<r-m){
        arr[k++]=right[j++];
    }
}
/// gfg verified
void mergeSort(int *arr,int l,int r){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge_util(arr,l,m,r);
    }

}

bool compBharmastra(int a,int b,unordered_map<int,int> &Map){
    int av = Map[a],bv=Map[b];

    if( av!=0 && bv!=0 )
        return av < bv;
    if(av!=0 && bv==0)
        return true;
    if (av==0 && bv!=0)
        return false;
    else
        return a<b;
}

/// it's little complicated needed to be explained start and end are starting and ending index
int partBharmastra(int arr[],int start,int end,unordered_map<int,int> &Map)
{
    /// what we do we choose a value as 'pivot' and put the pivot element in starting or
    /// ending (here in starting) i here is the index where we put the next element smaller than
    /// pivot

    int pivot=arr[start]; int i=start+1;

    /// j is iterator that iterate over array except the pivot that's why j starts with start+1
    for(int j=start+1;j<=end;j++)
    {
        if(compBharmastra(arr[j],pivot,Map))
        {
            swap(arr[i],arr[j]);
            i+=1;
        }
    }
    /// now i must be pointing to next position to put the element smaller than pivot, i-1 already
    /// has a element smaller than pivot so we swap pivot element arr[start] with i-1 placing pivot
    /// in right position
    swap(arr[start],arr[i-1]);

    return i-1;
}
/// this is bharmastra of sorting you put appropriate mycomp function and you will get the
/// wierdest sorting it's also NlogN.
void quick_sortBharmastra(int arr[],int start, int end,unordered_map<int,int> &Map)
{
    if (start<end){
        int pivot;
        pivot=partBharmastra(arr,start,end,Map);
        quick_sortBharmastra(arr,start,pivot-1,Map);
        quick_sortBharmastra(arr,pivot+1,end,Map);
    }

}

/// gfg similiar It's based on idea of partion algo of quicksort
void moveNegativeToLeftPositiveToRightOrderNotMatter(int arr[],int n){

    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}

/// gfg verified It's based on idea of partion algo of quicksort
void sortArrayHavingZerosAndOnes(int arr[],int n){

    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]<1){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}

void mergePositiveNegative(int arr[],int start,int m,int end){
    int left[m-start+1] ,right[end-m] ;

    for(int i=start,j=0;i<=m;i++,j++)
        left[j] = arr[i];
    for(int i=m+1,j=0;i<=end;i++,j++)
        right[j] = arr[i];

    int i=start,j=0;

    /// put left -ve into array
    while(j< m-start+1 ){
        if(left[j]<0){
            arr[i++] = left[j];
        }
        j++;
    }
    /// put right -ve into array.
    j = 0;
    while(j< end-m){
        if(right[j]<0){
            arr[i++] = right[j];
        }
        j++;
    }
    j=0;
    while(j< m-start+1 ){
        if(left[j]>0){
            arr[i++] = left[j];
        }
        j++;
    }
    j = 0;
    while(j< end-m){
        if(right[j]>0){
            arr[i++] = right[j];
        }
        j++;
    }

}

 void moveNegativeToLeftPositiveToRightOrderMatter(int arr[],int start,int end){
    if(start<end){
        int m = (start+end)/2;
        moveNegativeToLeftPositiveToRightOrderMatter(arr,start,m);
        moveNegativeToLeftPositiveToRightOrderMatter(arr,m+1,end);
        mergePositiveNegative(arr,start,m,end);
    }
 }

 bool sortElementsByFrequency_comp(pair<int,int> a,pair<int,int> b){
    if(a.second != b.second)
        return a.second > b.second;
    else
        return a.first < b.first;
}

 /// gfg leet verified O(NLogN) solution
 void sortElementsByFrequency(int arr[],int n){
    unordered_map<int,int> Map;
    unordered_map<int,int> :: iterator itr;
    for(int i=0;i<n;i++)
        Map[arr[i]]++;

    vector<pair<int,int>> v;

    for(itr=Map.begin();itr!=Map.end();itr++)
        v.push_back({itr->first,itr->second});

    sort(v.begin(),v.end(),sortElementsByFrequency_comp);

    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].second;j++)
            cout << v[i].first << " ";
    }
 }

void countInversionsInArray_util(int arr[],int low,int mid,int high,int &count){
    int n1 = mid-low + 1,n2 = high-mid;
    int left[n1],right[n2];

    for(int i=0,j=low;i<n1;i++,j++)
        left[i] = arr[j];
    for(int i=0,j=mid+1;i<n2;i++,j++)
        right[i] = arr[j];

    int i=0,j=0,k=low;
    while(i<n1 && j< n2){
        /// imp case here if count inversion only if element is greater not for same value
        if(left[i] <= right[j])
            arr[k++] = left[i++] ;
        else{
            count += n1-i;
            arr[k++] = right[j++] ;
        }
    }

    while(i<n1)
        arr[k++] = left[i++] ;
    while(j<n2)
        arr[k++] = right[j++] ;
}

/// gfg verified
void countInversionsInArray_(int arr[],int low,int high,int &count){
    if(low<high){
        int mid = (low+high)/2;
        countInversionsInArray_(arr,low,mid,count);
        countInversionsInArray_(arr,mid+1,high,count);
        countInversionsInArray_util(arr,low,mid,high,count);

    }
}

int countInversionsInArray(int arr[],int low,int high){
    int count = 0;
    countInversionsInArray_(arr,low,high,count);
    return count;
}

/// gfg verified leet code verified basically we are putting 0 to left and 2 to right and 1 should be
/// placed right if we put all zeros and 2 in right position
void sortArrayOf012(int arr[],int n){
    /// i0 next index to put zero i2 next index to put 2
    int i0=0,i2=n-1;

    for(int j=0;j<n;j++){
        /// as soon as the iterator crosses the i2 array must be sorted because now iterator would
        /// iteratre over the 2's partition which is already sorted
        if(j>i2)
            break;
        if(arr[j]==0){
            swap(arr[i0],arr[j]);
            i0++;
        }
        else if(arr[j]==2){
            swap(arr[i2],arr[j]);
            j--;   /// because we don't know what the number was at i2 position
            i2--;
        }
    }
}
/// gfg verified leet code verified
/// this function finds the min len subarray which on sorting makes whole array sorted
void minLengthSubArray(int arr[],int n){
    int i = 0;
    /// left sorted sequence
    while(i+1<n && arr[i] <= arr[i+1]){
        i++;
    }
    i++;
    if(i==n){
        cout << 0 << " " << 0;
        return;
    }
    int j= n-1;
    /// right sorted sequence
    while(arr[j-1] <= arr[j]){
        j--;
    }
    j--;
    if(j<i)
        i=j;
    cout <<"Value of i is "<< i << " and value of j " << j << "\n";
    int min_=INT_MAX,max_=INT_MIN;
    for(int k = i;k<=j;k++){
        if(arr[k] > max_)
            max_ = arr[k];
        if(arr[k]<min_)
            min_ = arr[k];
    }
    ///cout << "Value of max " << max_ << " and min " <<min_ << "\n";
    bool left=1,right=1;
    while( left || right){
        left = 0,right = 0;

        if(i-1>=0 && arr[i-1]>min_){
            if(arr[i-1]>max_)
                max_ = arr[i-1];
            i--;
            left = 1;
        }

        if(j+1<n && arr[j+1] < max_){
            if(arr[j+1] <min_)
                min_ = arr[j+1];
            j++;
            right = 1;
        }
    }

    cout << i <<" " << j ;
}

/// gfg verified
/// finds whether the arr2 is sub array of arr1 or not
bool isSubArray(int arr1[],int arr2[],int n1,int n2){
    if(n2>n1)
        return false;

    unordered_map<int,int> Map;
    unordered_map<int,int> :: iterator itr;

    for(int i=0;i<n2;i++)
        Map[arr2[i]]++;

    for(int i=0;i<n1;i++){
        if(Map[arr1[i]]==1)
            Map[arr1[i]] = 0;
    }

    bool flag = true;
    for(itr=Map.begin();itr!=Map.end();itr++){
        if(itr->second !=0){
            flag=false;
            break;
        }
    }

    return flag;
}
/// gfg verified I am not sure about this function
void sortKSortedArrayInsertionSort(int arr[],int n,int k){

    int key;
    for(int i=1;i<n;i++){
        key = arr[i];

        int j = i-1;
        while( j>=0 && arr[j]>key){
            swap(arr[j],arr[j+1]);
            j--;
        }
    }
}

/// gfg verified leet code gfg test cases are weak return abs diff b/w the pairs
/// try the algo with sorting only
int noOfPairsWithDiffK(int arr[],int n,int k){
    if(k<0)  /// abs diff can't be zero
        return 0;
    unordered_map<int,int> Map;
    int c = 0;
    for(int i=0;i<n;i++){
        if(k==0 ){
            if(Map[arr[i]] == 1)
                c++;
        }
        else{
            if( Map[arr[i] ] == 0 ){
                if(Map[ arr[i] +k ]!=0)
                    c++;

                if(Map[arr[i] -k]!=0 && (arr[i] + k )!= (arr[i]-k) )
                    c++;
            }
        }
        Map[arr[i]]++;
    }
    return c;
}

bool sortArrayAccordingToOrderDefinedByOtherArray_comp(int a,int b,unordered_map<int,int> &Map){
    int av = Map[a],bv=Map[b];

    if( av!=0 && bv!=0 )
        return av < bv;
    if(av!=0 && bv==0)
        return true;
    if (av==0 && bv!=0)
        return false;
    else
        return a<b;
}

int sortArrayAccordingToOrderDefinedByOtherArray_part(int arr[],int start,int end,unordered_map<int,int> &Map)
{
    int pivot=arr[start]; int i=start+1;
    for(int j=start+1;j<=end;j++)
    {
        if(sortArrayAccordingToOrderDefinedByOtherArray_comp(arr[j],pivot,Map))
        {
            swap(arr[i],arr[j]);
            i+=1;
        }
    }

    swap(arr[start],arr[i-1]);

    return i-1;
}

void sortArrayAccordingToOrderDefinedByOtherArray_sort(int arr[],int start, int end,unordered_map<int,int> &Map)
{
    if (start<end){
        int pivot;
        pivot=sortArrayAccordingToOrderDefinedByOtherArray_part(arr,start,end,Map);
        sortArrayAccordingToOrderDefinedByOtherArray_sort(arr,start,pivot-1,Map);
        sortArrayAccordingToOrderDefinedByOtherArray_sort(arr,pivot+1,end,Map);
    }

}

/// gfg verified leet code verified; logic was O(NLogN) but other stuff was time consuming
/// hitting map more than once cause double time, passing Map as value instead of refrence
/// causes TLE so better pass Map by refrence
void sortArrayAccordingToOrderDefinedByOtherArray(int arr1[],int arr2[],int n1,int n2){
    unordered_map<int,int> Map;

    for(int i=0;i<n2;i++){
        Map[ arr2[i] ] = i+1;
    }
    sortArrayAccordingToOrderDefinedByOtherArray_sort(arr1,0,n1-1,Map);
}

bool sortAccordingToSetBits_comp(int a,int b){
    int ca=0,cb=0;
    int x = a,y = b;

    while(x){
        if(x&1)
            ca++;
        x>>=1;
    }

    while(y){
        if(y&1)
            cb++;
        y>>=1;
    }
    return ca>cb;
}
/// gfg verified
/// std::stable_sort can be used for stale sorting
void sortAccordingToSetBits(int arr[],int n){
    sort(arr,arr+n,sortAccordingToSetBits_comp);
}

bool decresingSorting(int a,int b){
    return a>b;
}

/// gfg verified
void sortEvenIndexIncOddIndexDecreasing(int arr[],int n){
    int j=0;
    /// partition odd and even indexed elements
    for(int i=0;i<n;i++){
        if( (i&1)==0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    sort(arr,arr+j);
    sort(arr+j,arr+n,decresingSorting);
}

/// the standard insertion Sort gfg verified
void insertionSort(int arr[],int n){

    int key,j;
    /// the array to left of i is already sorted and we put key into right place
    for(int i=1;i<n;i++){  /// this loop picks each element one by one
        key = arr[i]; j = i-1;
        /// what we do here is that we shift the element larger than key by one place to right until either there are
        /// no elements left larger than key.
        while(j>=0 && arr[j]> key){
            arr[j+1] = arr[j];
            j--;
        }
        /// j+1 is right  place to put key in left side of i not in whole array
        arr[j+1] = key;
    }
}

int main() {
    int arr1[] = {-4, 6, 9, -1, 3};
    int arr2[] = {9,8,7,6,5,3};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    sortKSortedArrayInsertionSort(arr2,n2,2);
    for(int i=0;i<n2;i++)
        cout << arr2[i] << " ";
	return 0;
}
