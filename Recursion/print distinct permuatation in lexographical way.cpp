#include <iostream>
#include<algorithm>
#include<cstring>

using namespace std;

/// this basically return false if their is any duplicate charater in given range of string mathing with end index.
bool safeToSwap(char str[], int start, int end)
{
    for (int i = start; i < end; i++)
        if (str[i] == str[end])
            return 0;
    return 1;
}

/// Prints all distinct permutations in lexographical order.
void findPermutations(char str[], int index, int n)
{
    if (index >= n) {
        cout << str << "\n";
        return;
    }
    /// to produce output in lexo order we sort the given string or substring.
    sort(str+index,str+n);
    /// we store the sorted sting as it wouldn't be restored after swapping.
    char orignal[10];
    strcpy(orignal,str);
    for (int i = index; i < n; i++) {
        /// index represents starting point of string or substring we iterate from starting point to end of string.
        /// we only swap charaters if they don't match index represents starting point and i represents
        /// the position of charater we intend to swap if the ith charter matches with any charter before it
        /// we don't swap because that would produce repeated permuations.
        if (safeToSwap(str, index, i)) {
            swap(str[index], str[i]);
            findPermutations(str, index + 1, n);
            /// we copy back orinal string.
            strcpy(str,orignal);
        }
    }
}

int main()
{
    char str[10];
    cin >> str;
    int n = strlen(str);
    findPermutations(str, 0, n);
    return 0;
}
