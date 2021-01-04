#include <iostream>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;

int main() {
    string s = "My Name is Kashish I am a Student of UIET MDU",word,reversed;
    reverse(s.begin(),s.end());
    stringstream ss(s);
    while(ss>>word){
        reverse(word.begin(),word.end());
        reversed +=word;
        reversed +=" ";
    }
    cout << reversed;
	return 0;
}
