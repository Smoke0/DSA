#include<bits/stdc++.h>
using namespace std;

/// works like expected but still might face issues
void toTitleCase(string s){

    bool flag = true;
    for(int i=0;i<s.length();i++){
        if(flag){
            if(s[i] >='a' && s[i]<='z'){
                s[i]-=32;
                flag = false;
            }
            else if(s[i] >='A' && s[i]<='Z'){
                flag = false;
            }

        }
        else if(!flag && s[i]==' ')
            flag = true;
    }

    cout << s;
}

/// gfg verified anagram are string having same charaters but different arrangment
bool areAnagram(string a,string b){

    if(a.length()!=b.length())
        return false;

    int stuff[26] = {0};
	    for(int i=0;i<a.length();i++)
	        stuff [ a[i]-'a' ]++;
        for(int i=0;i<b.length();i++)
	        stuff [ b[i]-'a' ]--;

        int i;
        for(i=0;i<26;i++){
            if(stuff[i] !=0)
                break;
        }
        if(i==26)
            return true;
        else
            return false;
}

/// in strings sub strings and sub sequences are different not same sub sequence is like sub set
/// but substrings are continues strings of all possible length

void printSubStrings(string s){
    /// i is length of string we want to print j is starting point
    for(int i=1;i<=s.length();i++){
        for(int j=0;j<s.length();j++){
            /// this if check that whether the this of this length from this starting pt.is possible or not
            if(j+i<=s.length()){
                for(int k=j;k<s.length() && k<j+i;k++)
                    cout <<s[k];
                cout << "\n";
            }
        }
    }
}

/// gfg verified
void largestPalindromeSubString(string s){
    int len = s.length();
    bool dp[len][len] = {0}; /// store whether the string starting from row no i to column no j is
                             /// palindrome or not
    /// all strings of length 1 are palindrome
    int start=0, maxLen = 1;
    for(int i=0;i<len;i++)
        dp[i][i] = 1;

    /// string of length two for string of size 2 to be palindrome it's both char must match
    for(int i=0;i<len-1;i++){
        if(s[i]==s[i+1]){
            dp[i][i+1] = 1;
            if (maxLen < 2){
                start = i;
                maxLen = 2;
            }
        }
    }
    /// check for string of len k
    for(int k=3;k<=len;k++){
        /// i is starting point and j is ending point
        for(int i=0;i<len-k+1;i++){
            int j = i+k-1;
            /// if string b/w ith and jth charater is palindrome and ith and jth char are same then
            /// string from i to j must be palindrome
            if( dp[i+1][j-1] && s[i]==s[j]){
                dp[i][j] = 1;
                if( k > maxLen){
                    start = i;
                    maxLen = k;
                }

            }
        }
    }
    /// prints largest palindrome
    for(int z=start;z<=start+maxLen-1;z++)
        cout << s[z];
}

int main() {
    largestPalindromeSubString("kjqlrzzfmlvyoshiktodnsjjp");
	return 0;
}
