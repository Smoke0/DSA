/// a wonderfull algorithm for finding the number of possible triangle in array.
/// It's geeksforgeeks implementation.
/// what it does it has three elements arr[i] arr[j] and arr[k] it tries to find the right most k
/// for which arr[k] < arr[i] + arr[j] now as i and k are fixed we increment j and we find triangles possible
/// for a particular i
#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    int n,count =0,t;
        cin >>n;
        count = 0;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    for(int i=0;i<n-2;i++){
        int k=i+2;
        for(int j=i+1;j<n-1;j++)
        {
            /// loop runs only once for a particular value of i not every j that's why it's o(n^2).
            while(k<n && arr[i]+arr[j] > arr[k])
                k++;
            count+= k-j -1;
        }
    }
    cout << count ;

	return 0;
}
