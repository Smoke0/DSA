#include <bits/stdc++.h>
using namespace std;

/// returns kth bit counting from right side  nth n-1......3 2 1 bit
bool kthBit(long long x,int k){
    return x & (1<<k-1);
}

/// gfg verified
/// returns whether binary representation of int is palindrome or not
bool isBinaryPalindrome(long long x){
    int l = 1;
    int r = 0; /// no of bits no has
    /// r<64 is for case where number is max value of long long
    while(r<64){
        if ( x < (1<<r) )
            break;
        r++;
    }

    while(l<r){
        if (kthBit(x,r) !=kthBit(x,l))
            return false;
        r--;l++;
    }
    return true;
}

int main() {
    cout << isBinaryPalindrome(17);
	return 0;
}
