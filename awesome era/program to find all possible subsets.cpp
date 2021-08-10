#include<bits/stdc++.h>
using namespace std;

int main(){
    string arr;
    cin>>arr;
    int len = arr.length();

    for(int i=0;i<1<<len;i++){

        for(int j=len-1;j>=0;j--){
            int x = i&1<<j;

            if(x>0)
                cout<<arr[len-1-j];

        }

        cout<<"\n";
    }

    return 0;
}
