/// This program is intented to get you familiar with string syntax.
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string str,str2 = ("It's string class baby"),str3;
    cout<<"\nEnter a number followed by a line\n";
    cin>>n;
    cin.ignore();
    ///getline fn is used for inputting a stream from stdin with spaces in b/w you can't do this with cin>>str;
    /// so getline stops taking input asap it encounters a /n and cin by default skips /n so when cin>>n exe
    /// it leaves a /n in buffer so to clear buffer we user cin.ignore.
    getline(cin,str);
    //cout<<str;
    /// str.clear deletes the contents of string.
    str.clear();
    /// push back is used for pushing a char at end of string;
    /// similiar fn is pop back for removing one char from behind.
    /// str.length for finding string length
    for(char ch ='a';ch<'p';ch++)
        str.push_back(ch);
    //cout<<str;
    /// str.swap(str2) swaps the content of two strings
    str.swap(str2);
    /// strings can be assingned in cpp now str3 is same as str
    str3= str;
    /// strings can be appende in cpp like str += str2 or str.append(str2);
    str+=str2;
    str.clear();
    str2.clear();
    str3.clear();
    str = "Kash";
    str2 = "Kashish";
    str3 = "smoke";
    /// str.find very useful function return index of substring first encountered. return string::npos if noting found.
    /*if(str.find("ish")!=string::npos){
        cout<<"Found at index "<<str.find("ish")<<"\n";
    }
    else{
        cout<<"\n Not found\n";
    }*/
    /// str.substr(a,b) returns sub string starting from index a of len b. if b is not passed string until end
    /// is considered.
    //cout<<str.substr(2,3)<<"\n";
    //cout<<str.substr(2);
    /// str.erase (a,b) deletes b char staring from index a;
    //str.erase(0,2);
    /// string.insert(a,string) insert string at index a;
    //str.insert(0,"smoke ");
    /// str.compare(str2) return 0 is same else return something IDK yet.
    //cout<<str.compare(str2);
    return 0;
}
