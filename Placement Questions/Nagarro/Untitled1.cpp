#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[],int n){
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << "\n";
}

/// similar question sort arrays of ones and zeros gfg verified approach
void rearrangePosNeg(int arr[],int n){
    int j=0;

    for(int i=0;i<n;i++){

        if(arr[i]<0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}

bool sortArrayBasedOnAbsValues_comp(int a,int b){
    return abs(a) < abs(b);
}

void sortArrayBasedOnAbsValues(int arr[],int n){
    sort(arr,arr+n,sortArrayBasedOnAbsValues_comp);
}


bool getKthRightBit(long long int N,int k){
    return N & ( 1<<(k-1));
}

int isPallindrome(long long int N){
    long long copy = N;
    int length = 0;

    while(copy!=0){
        copy = copy >> 1;
        length++;
    }

    int i = 1, j = length;
    while( i< j ){
        if( getKthRightBit(N,i) != getKthRightBit(N,j))
            return 0;
        i++;j--;
    }

    return 1;
}

int print2largest(int arr[], int n){
    int max_ = arr[0], max2=-1;
    for(int i=1;i<n;i++){

        if( arr[i] > max_ ){
            max2 = max_;
            max_ = arr[i];
        }

        else if( arr[i] < max_ && arr[i] > max2 ){
            max2 = arr[i];
        }

    }

    return max2;
}

void commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
    int i = 0,j=0,k=0;
            int x,y,z;
            int pre = INT_MIN;
            vector <int> output;
            while( i<n1 && j<n2 && k<n3){
                /// all are equal
                x = A[i]; y = B[j];  z = C[k];
                if(x == y && y == z){
                    if( x > pre ){
                        output.push_back(x);
                        pre = x;
                    }

                    i++;j++;k++;
                }
                else{
                    if( x < y  )
                        i++;

                    else if( y < z )
                        j++;

                    else
                        k++;

                }
            }

            for(int i=0;i<output.size();i++)
                cout << output[i] << " ";
}

int main() {

    int arr[] = {12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n = sizeof(arr)/sizeof(arr[0]);



	return 0;
}
