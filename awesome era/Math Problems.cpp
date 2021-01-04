#include<bits/stdc++.h>

using namespace std;

/// gfg verified
void primeFactors(int n2){
    vector <int> primes;
    while (n2 % 2 == 0)
    {
        primes.push_back(2);
        n2 = n2 >> 1;
    }
    for (int i = 3; i <= sqrt(n2); i = i + 2)
    {
        while (n2 % i == 0)
        {
            primes.push_back(i);
            n2 = n2/i;
        }
    }
    if (n2 > 2)
        primes.push_back(n2);

    for(int i=0;i<primes.size();i++)
        cout<<primes[i]<<" ";

}

int main(){
    primeFactors (225);
    cout << t;

    return 0;
}

