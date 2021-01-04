/// this is certainly crazisest pattern print it for some values of n to find out what pattern is.
#include<iostream>

using namespace std;

int main(){
    int no=1,n,row=1,i;
    int p_no;
    cin  >> n;
    if(n&1){
        while(row<=n){
        if(row==1){
            i = n;
            while(i>=1){
                cout << no++;
                if(i!=1)
                    cout <<"*";
                i--;
            }
        }
        else if(row <= n/2+1){
            i = n;
            no = no+n;
            while(i>=1){
                cout << no++;
                if(i!=1)
                    cout <<"*";
                i--;
            }
        }
        else{
            i = n;
            no = no-2*n;
            p_no = no;
            while(i>=1){
                cout << p_no++;
                if(i!=1)
                    cout <<"*";
                i--;
            }
        }
            row++;
            cout << "\n";
        }
    }
    ///  case of n being even.
    else{
        while(row<=n){
        if(row==1){
            i = n;
            while(i>=1){
                cout << no++;
                if(i!=1)
                    cout <<"*";
                i--;
            }
        }
        else if(row <= n/2){
            i = n;
            no = no+n;
            while(i>=1){
                cout << no++;
                if(i!=1)
                    cout <<"*";
                i--;
            }
        }
        else if(row == n/2+1){
            i = n;
            while(i>=1){
                cout << no++;
                if(i!=1)
                    cout <<"*";
                i--;
            }
        }
        else{
            i = n;
            if(row == n/2+2)
                no = no-n;
            no = no-2*n;
            p_no = no;
            while(i>=1){
                cout << p_no++;
                if(i!=1)
                    cout <<"*";
                i--;
            }
        }
            row++;
            cout << "\n";
        }
    }
    return 0;
}
