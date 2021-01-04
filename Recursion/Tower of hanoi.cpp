#include<iostream>

using namespace std;

void toh(int n,char source,char destination,char helper){
    /// base case
    if(n==1){
        cout <<"moving " << n <<"th from " <<source <<" to " << destination <<"\n";
        return;
    }
    /// recursive case.
    /// I am saying recursion to move n-1 disks from source to helper.
    toh(n-1,source,helper,destination);
    /// Now I am moving nth disk from source to destination myself
    cout <<"moving " << n <<"th from " <<source <<" to " << destination <<"\n";
    /// I am again asking recursion to move n-1 disks from helper to destination
    toh(n-1,helper,destination,source);
}

int main(){
    int n;
    cin >> n;
    toh(n,'A','C','B');
	return 0;
}
