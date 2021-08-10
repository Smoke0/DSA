#include<bits/stdc++.h>

using namespace std;

/// gfg leetcode verified the idea here is based on observation we have a max_ to store max value occurred yet.
/// temp here stores  sum of previous values. now the temp_ might be less than max_ also. we only break the continuity
/// when current element is greater than the previous values plus current element that is we break the chain only when the previous
/// values has more -ve  than positives
long long largestContSubArraySum(long long arr[],int n){
    long long max_  = arr[n-1],temp_=arr[n-1];
    int temp2=1,maxLen = 1; /// maxLen is length of maxSum sub array.
    for(int i=n-2;i>=0;i--){

        if(arr[i] > temp_ + arr[i]){
            temp_ = arr[i];
            temp2 = 1;
        }

        else{
            temp2++;
            temp_ = arr[i]+temp_;
        }
        if(temp_ > max_){
            maxLen = temp2;
            max_ = temp_;
        }

    }
    cout << maxLen <<"\n";
    return max_;
}

/// arrange array such that arr[i] = i;
void arrangeArray(long long  arr[],int n){

    for(int i=0;i<n;i++){
        if(arr[i]==i){
            continue;
        }
        else{
            /// place right element in ith position
            while( arr[i]!=-1 && arr[i]!=i){
                swap(arr[i],arr[arr[i]]);
            }
        }
    }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << "\n";
}

/// re arrange array such that +ve and -ve are alternating and element order is maintained as in original array.
/// gfg verified not optimized one
void arrangeArrayAlternatePosNeg(long long arr[],int n){
    int pc=0,nc=0;

    for(int i=0;i<n;i++){
        if(arr[i]>=0)
            pc++;
        else
            nc++;
    }

    int pos[pc],neg[nc],i=0,j=0;

    for(int k=0;k<n;k++){
        if(arr[k]>=0)
            pos[i++] = arr[k];
        else
            neg[j++] = arr[k];
    }

    int k; i=0,j=0;
    for(k=0;k<n;k++){
        if(i==pc || j==nc)
            break;
        if(k%2==0){
            arr[k] = pos[i++];
        }
        else{
            arr[k] = neg[j++];
        }
    }

    while(i<pc)
        arr[k++] = pos[i++];
    while(j<nc)
        arr[k++] = neg[j++];

}

/// gfg verified optimum
void moveAllZeroToRight(long long arr[],int n){
    int index=-1;


    for(int i=0;i<n;i++){
        if(index == -1 && arr[i]!=0){
            continue;
        }

        if(index==-1 && arr[i]==0){
            index = i;
        }

        if(index!=-1 && arr[i]!=0){
            swap(arr[index++],arr[i]);
        }
    }

}

/// gfg verified It use the concept of sliding window
int minSwapToBringLessThanEqualToKTogether(long long arr[],int n,int k){
    int windowSize = 0,windowCount=0,s=0,e,max_; /// window size is just size of window windowCount is count of elements
    /// <=k in window and s and e are starting and end of window and max_ is max no of <=k elements in window

    /// get size of window which is equals to no of elements <=k
    for(int i=0;i<n;i++)
        if(arr[i]<=k)
            windowSize++;


    e = windowSize-1;
    /// create window
    for(int i=s;i<=e;i++)
        if(arr[i]<=k)
            windowCount++;
    max_ = windowCount;

    while(e<n-1){
        e++;
        if(arr[e]<=k)
            windowCount++;
        if(arr[s]<=k)
            windowCount--;
        s++;

        max_ = max( windowCount,max_ );
    }

    return windowSize - max_;
}

void arrngeMinMaxForm(long long arr[],int n){

    int i=0,left,right;

    while(i!=n-1){
        left = i-0; right = n-1 - i;

        if(left < right){
            i = 2*left + 1;
            swap(arr[0],arr[i]);
        }
        else if(right <= left){
            i = 2*right;
            swap(arr[0],arr[i]);
        }

    }
}

void arrangeArrayAccToAnotherArray(long long arr[],long long index[],int n){

    for(int i=0;i<n;i++){
        while(index[i]!=i){
            swap( arr[i],arr[index[i]] );
            swap( index[i],index[ index[i] ]  );
        }
    }
}

/// standard quick sort partition method
int part(int arr[],int start,int end)
{
    int pivot=arr[start]; int i=start+1;
    for(int j=start+1;j<=end;j++)
    {
        if(arr[j]<pivot)
        {
            swap(arr[i],arr[j]);
            i+=1;
        }
    }
    swap(arr[start],arr[i-1]);

    return i-1;
}

int randomPartition(int arr[], int l, int r)
{
    int n = r-l+1;
    int pivot = rand() % n;
    swap(arr[l + pivot], arr[r]);
    return part(arr, l, r);
}

/// gfg leet verified works better with random partition sometimes we need to find kth smallest array so we take advantage of fact
/// that the quicksort places the pivot element in correct position.
/// kth largest is (n-k+1) smallest
int kthSmallestElement(int arr[],int start,int end,int k){
    int pivot  = randomPartition(arr,start,end);

    if(pivot-start ==k-1){ /// if pivot element is the kth we are done
        return arr[pivot];
    }
    else if(pivot-start < k-1){ /// the kth smallest element is present in right half
        return kthSmallestElement(arr,pivot+1,end,(k-(pivot-start)-1)); /// we update start end and k accordingly
    }
    else{ /// kth present in left half
        return kthSmallestElement(arr,start,pivot-1,k);
    }
}

int smallestMissingNoUnSorted(int arr[],int n){
    int l=1 , h,j;

     for(j=0;j<n;j++){
        if(arr[j]>0){
            l = h = arr[j];
        }
     }

    for(int i=j+1;i<n;i++){

        if(arr[i]<1)
            continue;

        if(arr[i]==h+1)
            h = arr[i];
        else if( arr[i] < l ){
            if(arr[i]==l-1)
                l = arr[i];
            else{
                l = h = arr[i];
            }
        }
    }

    if(l>1)
        return 1;
    else{
        return h+1;
    }
}

/// gfg verified kind of like kandane's algo the Idea is we store largest element appeared on right if any larger element
/// occurs we update the largest element else we calculate the diff b/w max so far and current element and update max_diff
/// accordingly
int maxDiffSuchThatLargerElementAfterSmaller(int arr[],int n){

    int max_diff = -1 , msf = arr[n-1];

    for(int i=n-2;i>=0;i--){
        if(arr[i]> msf)
            msf = arr[i];
        else if(msf - arr[i]>max_diff)
            max_diff = msf - arr[i];
    }

    return max_diff;

}

bool pairArr_comp(pair<int,int> a,pair<int,int> b){
    return a.first < b.first;
}

/// O(NLogN) solution but O(N) required
int findFarthestElementsLargerElementAppearsInRight(int arr[],int n){
    pair<int,int> pairArr[n];

    for(int i=0;i<n;i++)
        pairArr[i] = {arr[i],i};

    /// stable_sort is very imp here
    stable_sort(pairArr,pairArr+n,pairArr_comp);
    /// now problem reduces to finding maxDiff s.t. larger element appear on right

    int max_diff = -1 , msf = pairArr[n-1].second;

    for(int i=n-2;i>=0;i--){
        if(pairArr[i].second> msf)
            msf = pairArr[i].second;
        else if(msf - pairArr[i].second>max_diff)
            max_diff = msf - pairArr[i].second;
    }

    return max_diff;

}

/// gfg verified in array find min distance b/w no x and y if present
int minDistbwXandY(int arr[], int n, int x, int y) {
    /// we simply store the last position of x and y
    int lastx=-1,lasty=-1,min_=INT_MAX;

    for(int i=0;i<n;i++){
        /// we update the position of x and y
        if(arr[i]==x)
            lastx = i;
        else if(arr[i]==y)
            lasty = i;
        /// update min distance
        if(lastx != -1 && lasty != -1)
            min_ = min(min_,abs(lastx-lasty));
    }

    if( lastx != -1 && lasty != -1 )
        return min_;
    else
        return -1;  /// if x and y both are not present
}

/// gfg simliar given element in range [0,k-1] where k<=n we need to find max repeating element the idea is we add k to
/// index of element as we are modifying arr we take mode with k now max repeating element would be max element index in modified
/// arr because the k would be added to that index max times this doesn't work if there are more than one repeating element
int maxRepeatingElement(int arr[],int n,int k){
    int max_ = INT_MIN,max_idx;
    for(int i=0;i<n;i++)
        arr[arr[i]%k]+=k;

    for(int i=0;i<n;i++){
        if(arr[i]>max_){
            max_ = arr[i];
            max_idx = i;
        }
    }

    return max_idx;
}
/// leetcode verified given element in range [1,n] and arr of size n+1 find repeating element
int duplicateElement(int arr[],int n){

    for(int i=0;i<n;i++){
    /// already in correct position
        if( i == arr[i]-1 )
            continue;
        else{
            /// place elements in correct position
            while( i!=arr[i]-1 ){
                /// if arr[ arr[i]-1] already has correct element then arr[i] must be duplicate
                if( arr[i] == arr[ arr[i]-1]  )
                        return arr[i];
                swap( arr[i],arr[ arr[i]-1]);
            }
        }
    }
}

/// leet code verified the idea here is extension of majority element in case of n/2 there are only 2 numbers possible
/// so we keep track of potiential candidates.
void majorityElementN_3(int arr[],int n){
    int m1,m2,c1=0,c2=0;  /// m1 and m2 are candidates and c1 and c2 is count of same.

        for(int i=0;i<n;i++){
            /// no candidate so add element as candidate
            if(c1==0 && c2==0){
                m1 = arr[i];
                c1++;
            }
            else if(c1==0 && c2!=0){
                if(m2==arr[i]) /// no already present increment it's count
                    c2++;
                else{
                    m1 = arr[i]; /// add new candidate
                    c1++;
                }
            }
            else if(c2==0 && c1!=0){
                if(m1==arr[i])
                    c1++;
                else{
                    m2 = arr[i];
                    c2++;
                }
            }
            else{
                if(m1==arr[i])
                    c1++;
                else if(m2==arr[i])
                    c2++;
                else{ /// if arr[i] doesn't match with any of candidate we decrement count of both by one
                    c1--;c2--;
                }
            }

        }

        /// check whether m1 and m2 are majority element or not
        if(c1!=0){
            int m1Count = 0;
            for(int i=0;i<n;i++){
                if(arr[i]==m1)
                    m1Count++;
            }
            if(m1Count>(n/3))
                cout << m1 << " ";
        }
        if(c2!=0){
            int m2Count = 0;
            for(int i=0;i<n;i++){
                if(arr[i]==m2)
                    m2Count++;
            }
            if(m2Count>(n/3))
                cout << m2 << " ";
        }
}

/// gfg verified very basic question
int maxSumPathInTwoSortedArrays(int arr1[],int arr2[],int n1,int n2){

    int i = 0,j = 0,sum1=0,sum2=0,sum=0;

    while(i<n1 && j < n2){
        if(arr1[i] < arr2[j])
            sum1+=arr1[i++];
        else if(arr1[i] > arr2[j])
            sum2+=arr2[j++];
        else{
            if(sum1 > sum2)
                sum+=sum1;
            else
                sum+=sum2;
            sum+=arr1[i];
            i++;j++;
            sum1 = sum2 = 0;
        }
    }

    while(i<n1)
        sum1+=arr1[i++];
    while(j<n2)
        sum2+=arr2[j++];

    if(sum1 > sum2)
        sum+=sum1;
    else
        sum+=sum2;

    return sum;
}

/// gfg verified
int binarySearch(int arr[],int s,int e,int key){
    int m ;

    while(s<=e){
        m = (s+e)/2;
        if(key == arr[m])
            return m;
        if(key == arr[s])
            return s;
        if(key == arr[e])
            return e;
        else if(key > arr[m])
            s = m+1;
        else
            e = m-1;
    }

    return -1;
}

/// gfg verified O(NLogN) solution for each element find smallest greater element
void smallestGreaterElementOfWholeArray(int arr[],int n){

    int sorted[n],index;
    for(int i=0;i<n;i++)
        sorted[i] = arr[i];

    sort(sorted,sorted+n); /// simply sort the array

    for(int i=0;i<n;i++){
        index = binarySearch(sorted,0,n-1,arr[i]);
        if(index == n-1)
            cout << "_ ";
        else
            cout << index+1 <<" ";
    }
    cout << "\n";
}

/// gfg verified but idea is kind of clumsy but O(N) approach
int flipMZerosForMaxConsecutiveOnes(int arr[],int n,int m){
    queue<int> q;
    int max_len=INT_MIN,min_index;
    int start = 0,end =-1;
    /// in case of m == 0 we find longest consecutive ones
    if(m==0){
        int len = 0;
        for(int i=0;i<n;i++){
            if(arr[i]==1)
                len++;
            else
                len = 0;
            max_len = max( max_len,len);
        }
        return max_len;
    }
    /// else we find longest consecutive ones with m zeros in it. we use queue to keep track of index of zeros
    for(int i=0;i<n;i++){
        if(arr[i]==1)  /// one are always welcome
            end++;


        else{
            if(q.size() < m){  /// less than m zeros are added to window
                q.push(i);
                end++;
            }
            else {  /// we add the new zero but we discard last zero updating start and end of window
                min_index = q.front();
                q.pop();
                start = min_index+1;
                q.push(i);
                end++;
            }
        }

        max_len = max( max_len,end-start+1);
    }

    return max_len;
}

/// gfg verified
int noOfStrictlyIncreasingSubArrays(int arr[],int n){
    int count = 0,len = 1;
    /// simply count the length of strictly increasing sub array
    for(int i=1;i<n;i++){

        if(arr[i] > arr[i-1])
            len++;
        else{
            count += (len*(len-1))/2; /// when continuity breaks we simply add the no of sub arrays for same
            len = 1;               /// len = 1 for element that just broke continuity
        }
    }
    count += (len*(len-1))/2;  /// for last val of len
    return count;
}

/// gfg verified  idea is simply to create a minHeap of size k and keep track of k largest elements yet
 void kthLargestElementInStream(int arr[],int n,int k){
    /// STL minHeap
    priority_queue<int , vector<int> , greater<int> > minHeap;

    for(int i=0;i<n;i++){
        if(minHeap.size() < k-1){
            minHeap.push(arr[i]);
            cout << "-1 ";
        }
        else if(minHeap.size()==k-1){
            minHeap.push(arr[i]);
            cout << minHeap.top() << " ";
        }
        else {
            if(arr[i] > minHeap.top()){
                minHeap.pop();
                minHeap.push(arr[i]);
            }
            cout << minHeap.top() << " ";
        }
    }
 }

 /// gfg verified sliding window concept
 void smallestSubArrWithSumGreaterThanX(int arr[],int n,int x){

    int winSum = 0, winStart=0,winEnd=-1;
    int minStart=0,minEnd=INT_MAX;
    for(int i=0;i<n;){
        /// increasing window
        if(winSum <= x){
            winEnd++;
            winSum+=arr[i];
            i++;

            if( winSum > x && minEnd-minStart > winEnd - winStart ){
                minEnd = winEnd;
                minStart = winStart;
            }
        }
        /// decreasing window

        while ( winSum > x ){
            winSum-=arr[winStart];
            winStart++;

            if( winSum > x && minEnd-minStart > winEnd - winStart ){
                minEnd = winEnd;
                minStart = winStart;
            }
        }

    }

    cout << minEnd - minStart + 1;
}

int minStepsToTargetArr(int arr[],int n){

    int count = 0;
    int min_ =INT_MAX;
    while(1){
        min_ =INT_MAX;
        /// make sure all no except ones are even
        for(int i=0;i<n;i++){
            if(arr[i]>1 && (arr[i]&1)==1 ){
                cout << "Odd ones \n";
                count++;
                arr[i]--;
            }
            if(arr[i]!=1)
                min_ = min(min_,arr[i]);
        }

        if(min_ == INT_MAX){
            count+=n;
            break;
        }

        /// make min element one
        for(int i=0;i<n;i++){
            if( arr[i]!=1 )
                arr[i]/=min_;
        }
        cout << "Adding min/2 to count " << min_/2 << "\n";
        count +=min_/2;

    }

    return count;
}

/// gfg verified surprisingly good question
int minMergeOperationToMakePalindrome(int arr[],int n){
    int i = 0, j = n-1;
    int merges = 0;

    while(i<j){
        /// obvious
        if(arr[i]==arr[j]){
            i++; j--;
            continue;
        }
        else{
            /// we merge smaller element hoping it would become equal to larger one
            if(arr[i] < arr[j]){
                arr[i+1]+=arr[i];
                i++;
                merges++;
            }
            else{
                arr[j-1]+=arr[j];
                j--;
                merges++;
            }
        }
    }

    return merges;
}

int longestSpanWithSameSumInTwoBinaryArrays(int arr1[], int arr2[] ,int n){
    int s1 = 0 , s2 = 0, max_ = 0, start = 0,end = 0;

    int expan, reduce;
    s1+=arr1[0]; s2+=arr2[0];

    while(end<n-1){
        if( s1-s2 == 0 )
            max_ = max(max_,end-start+1);

        expan = abs( (s1 + arr1[end+1]) - (s2 + arr2[end+1]) );
        reduce = abs( (s1 - arr1[start]) - (s2 - arr2[start]) );

        if( expan == reduce ){
            end++;
            s1+=arr1[end]; s2+=arr2[end];
        }
        else if( expan <= n-1-end){
            end++;
            s1+=arr1[end]; s2+=arr2[end];
        }
        else{
            s1-=arr1[start]; s2-=arr2[start];
            start++;
            /// case where a new window of size 1 is created
            if(start > end){
                end = start;
                s1+=arr1[start];
                s2+=arr2[start];
            }

        }
    }

    if( s1-s2 == 0 )
        max_ = max(max_,end-start+1);
    return max_;
}

/// gfg verified
/// standard impl. of insertion sort will work without modification here.
/// we can optimize using min heap here create heap of size k+1 as every element is at most k place far from it's position
/// insert first k+1 elements now the smallest element must be present as it could be far by only k places extract min
/// put in first position and then add next element and proceed
void sortKSortedArr(int arr[],int n,int k){
    priority_queue<int, vector<int>,greater<int>> minHeap;
    int j = 0;

    for(int i=0;i<=k;i++)
        minHeap.push(arr[i]);

    for(int i=0;i<=(n-k-2);i++){
        arr[j++] = minHeap.top();
        minHeap.pop();

        minHeap.push(arr[i+k+1]);
    }

    while(!minHeap.empty()){
       arr[j++] = minHeap.top();
        minHeap.pop();
    }
}

/// gfg verified find the sum of elements whose sum is closest to zero
int closestToZero(int arr[],int n){
    sort(arr,arr+n);
    int i = 0, j = n-1;
    int min = arr[i] + arr[j],temp;
    temp = min;
    while(i<j-1){
        if(temp < 0)
            i++;
        else
            j--;
        temp = arr[i] + arr[j];
        if( abs(temp) < abs(min) )
            min = temp;
    }

    return min;
}

/// gfg verified idea is to create copy of arr sort it and swap the arr[i] until it's at correct position
int minSwapsToSortArray(int arr[],int n){

    int sorted[n],minSwaps = 0,index;
    for(int i=0;i<n;i++)
        sorted[i] = arr[i];

    sort(sorted,sorted+n);

    for(int i=0;i<n;i++){
        index = binarySearch(sorted,0,n-1,arr[i]);

        while(index != i){
            swap(arr[i],arr[index]);
            minSwaps++;
            index = binarySearch(sorted,0,n-1,arr[i]);
        }
    }

    return minSwaps;
}

vector<int> unionOfSortedArrays(int arr1[],int arr2[],int n,int m){
    int i = 0, j = 0;
    vector<int> out;

    while(i<n && j< m){
        if( arr1[i] == arr2[j] ){
            out.push_back(arr1[i]);
            i++; j++;
        }
        else if(arr1[i] < arr2[j])
            out.push_back(arr1[i++]);
        else
            out.push_back(arr2[j++]);
    }

    while(i<n)
        out.push_back(arr1[i++]);

    while(j<m)
        out.push_back(arr2[j++]);

    return out;
}

vector<int> intersectionOfSortedArrays(int arr1[],int arr2[],int n,int m){
    int i = 0, j = 0;
    vector<int> out;

    while(i<n && j< m){
        if( arr1[i] == arr2[j] ){
            out.push_back(arr1[i]);
            i++; j++;
        }
        else if(arr1[i] < arr2[j])
            i++;
        else
            j++;
    }

    return out;
}

/// gfg verified given there are no duplicates in arrays
vector<int> unionOfArrays(int arr1[],int arr2[],int n,int m){
    unordered_map<int,int> map1;
    unordered_map<int,int> map2;
    unordered_map<int,int> :: iterator itr;
    vector<int> out;

    for(int i=0;i<n;i++)
        map1[ arr1[i] ]++;

    for(int i=0;i<m;i++)
        map2[ arr2[i] ]++;

    for(itr=map1.begin();itr!=map1.end();itr++){
        if( map2.find(itr->first) == map2.end() )
            out.push_back(itr->first);
    }

    for(itr=map2.begin();itr!=map2.end();itr++)
        out.push_back(itr->first);

    return out;
}

/// gfg verified handle duplicates as well
vector<int> intersectionOfArrays(int arr1[],int arr2[],int n,int m){
    unordered_map<int,int> map1;
    unordered_map<int,int> map2;
    unordered_map<int,int> :: iterator itr;
    vector<int> out;

    for(int i=0;i<n;i++)
        map1[ arr1[i] ]++;

    for(int i=0;i<m;i++)
        map2[ arr2[i] ]++;

    for(itr=map1.begin();itr!=map1.end();itr++){
        if( map2.find(itr->first) !=map2.end() ) {
            int times = min( itr->second , map2[ itr->first] );
            for(int i=0;i<times;i++)
                out.push_back( itr->first  );
        }
    }

    return out;
}



/// -----------------------------------------------------------------------------------------------------------------------
///------------------------------------------------- array searching-------------------------------------------------------
/// -----------------------------------------------------------------------------------------------------------------------

int equilibriumPoint(int arr[],int n){
    long sum = 0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    long leftSum = 0;

    for(int i=0;i<n;i++){
        if( 2*leftSum == sum-arr[i])
            return i+1;

        leftSum+=arr[i];
    }

    return -1;
}

int minElement(int a,int b,int c){
      return min( a, min(b,c) );
  }

  int maxElement(int a,int b,int c){
      return max( a, max(b,c) );
  }

vector<int> smallestDifferenceTriplet(int a[], int b[], int c[], int n){

        vector<int> out;
        sort(a,a+n);
        sort(b,b+n);
        sort(c,c+n);

        int i = 0, j = 0, k = 0;
        int minDiff = INT_MAX;

        while( i<n && j<n && k< n ){

            int min_ = minElement( a[i],b[j],c[k] );

            if(  minDiff > maxElement( a[i],b[j],c[k]) -  min_ ){

                cout << "Executed\n";
                minDiff = maxElement( a[i],b[j],c[k]) -  min_;
                out.clear();
                out.push_back( a[i]);
                out.push_back(b[j]);
                out.push_back( c[k]);
            }


            if( a[i] == min_ )
                i++;
            else if( b[j] == min_ )
                j++;
            else
                k++;
        }

        sort( out.begin(), out.end(), greater<int>() );

        return out;
    }


int main(){
    ///4 52 55 100 33 61 77 69 40 13 27 87 95 40 96 71 35 79 68 2 98 3 18 93 53 57 2 81 87 42 66 90 45 20 41 30 32 18 98 72 82 76 10 28 68 57 98 54 87 66 7 84 20 25 29 72 33 30 4 20 71 69 9 16 41 50 97 24 19 46 47 52 22 56 80 89 65 29 42 51 94 1 35 65 25
    int arr1[] = {5,2,8},arr2[] = {10,7,12}, arr3[] = {9,14,6};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    ///cout << minSwapsToSortArray(arr1,n1);
    ///printArray(arr1,n1);
    vector<int> out = smallestDifferenceTriplet(arr1,arr2,arr3,n1);

    for(auto i:out)
        cout << i <<" ";

    return 0;
}
