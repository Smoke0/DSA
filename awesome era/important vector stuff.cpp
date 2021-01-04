#include<bits/stdc++.h>
using namespace std;

bool com(pair<int,int> s1,pair<int,int> s2){
    return s1.second<s2.second;
}
int main(){
    vector<int> arr;
    vector<int>::iterator it;
    for(int i=1;i<=5;i++)
        arr.push_back(i*2);
    it = arr.begin()+2;
    ///  insert allow us to insert elemet in between vector where push_back only allows insertion at end.
    arr.insert(it,56);
    it = arr.begin()+1;
    /// erase use for erasing element ar specific position.
    arr.erase(it);
    /// erasing a range of elements same can be done for insertion.
    for(int i=0;i<=2;i++){
        it = arr.begin()+i;
        arr.erase(it);
    }
    arr.clear();
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    return 0;
}
