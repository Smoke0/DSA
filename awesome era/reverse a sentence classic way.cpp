#include <iostream>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;

void reverseString(string &s,int len){
    char ch;
    for(int i=0;i<len/2;i++){
        ch = s[i];
        s[i] = s[len-1-i];
        s[len-1-i] = ch;
    }
}

int main() {
    string s = "My Name is Kashish I am a Student of UIET MDU",word,reversed;
    int len = s.length(),i=0,j,k; char ch;
    reverseString(s,len);
    /// this loop splits the words from sentence and also reverse them and them into reversed string.
    while(i<len){
        while(s[i]!='.' && i<len){
            word.push_back(s[i++]);
        }
        reverseString(word,word.length());
        reversed+=word+" ";
        word.clear();
        i++;
    }
    s = reversed;
    cout <<s;
	return 0;
}
