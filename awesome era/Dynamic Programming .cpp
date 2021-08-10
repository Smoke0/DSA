#include<bits/stdc++.h>
using namespace std;

struct val{
    int first;
    int second;
};

/// gfg verified ugly numbers are no starting from 1 which are multiple of 2,3,5 only
/// so we are generating the nxt multiples and filling up array accordingly
int uglyNumbers(int n){
    int arr[n];
    int nxt2=2,nxt3=3,nxt5=5;
    arr[0] = 1;
    int i2=0,i3=0,i5=0;

    for(int i=1;i<n;i++){
        arr[i]= min( nxt2, min(nxt3,nxt5) );

        if(arr[i] == nxt2){
            i2++;
            nxt2 = arr[i2]*2;
        }

        if(arr[i]== nxt3){
            i3++;
            nxt3 = arr[i3]*3;
        }

        if(arr[i]==nxt5){
            i5++;
            nxt5 = arr[i5]*5;
        }
    }

    return arr[n-1];
}

int goldMineProblem_rec(int arr[][10],int dp[][10],int n,int m,int i,int j=0){

    if(j==m)
        return 0;

    /// check whether the point is fissible
    if( i>=0 && i<n && j<m){

        if ( dp[i][j] == -1){
            /// explore right
            int op1 = goldMineProblem_rec(arr,dp,n,m,i,j+1);
            /// explore right upward
            int op2 =goldMineProblem_rec(arr,dp,n,m,i-1,j+1);
            /// explore right downward
            int op3 =goldMineProblem_rec(arr,dp,n,m,i+1,j+1);
            dp[i][j] =  arr[i][j] + max(op1,max(op2,op3) );
        }

        return dp[i][j];
    }
    return 0;
}

/// gfg verified this problem is of an array having some values and and there are certain moves
/// that are allowed we need to find max value of path.
int goldMineProblem(int arr[][10],int n,int m){
    int max_ = INT_MIN;
    int dp[10][10];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            dp[i][j] = -1;

    /// iterate through all starting points
    for(int i=0;i<n;i++){
        goldMineProblem_rec(arr,dp,n,m,i);
    }

    for(int i=0;i<n;i++){
        if(dp[i][0] > max_ )
            max_ = dp[i][0];
    }

    return max_;
}

/// gfg verified basic idea here is to formulate the question and apply dp
/// question is to find no of ways n people can be arranged such that any ith person may be
/// single or paired up with someone. now nth person can be either remain single or paired with
/// rest of n-1 persons so formula becomes f(n)  = f(n-1){where person remains single} + (n-1)*f(n-2)
/// {where person paired with any of n-1 persons and f(n-2) is for finding the arrangments of n-2 people because 2 are paired}
int friendPairingProblem(int n){
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2;i<=n;i++)
        dp[i] = dp[i-1] + (i-1)*dp[i-2];

    return dp[n];
}

bool subsetSumProblem_rec(int arr[],int n,int sum,int arrSum,int i){

    if(i<0){
        if(sum == arrSum)
            return true;
        return false;
    }

    if(sum == arrSum)
        return true;

    return subsetSumProblem_rec(arr,n,sum,arrSum,i-1) ||
            subsetSumProblem_rec(arr,n,sum,arrSum-arr[i],i-1);

}

bool subsetSumProblem(int arr[],int n,int sum){
    int arrSum = 0;

    for(int i=0;i<n;i++)
        arrSum+=arr[i];

    return subsetSumProblem_rec(arr,n,sum,arrSum,n-1);
}

/// gfg leet verified
bool subsetSumProblemDP(int arr[],int n,int sum){
    bool dp[sum+1][n+1];

    for(int i=0;i<=sum;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                if(j==0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1;
            }
            else if(i>=arr[j-1])
                dp[i][j] = dp[i-arr[j-1] ][j-1] || dp[i][j-1 ];
            else
                dp[i][j] = dp[i][j-1];
        }
    }

    return dp[sum][n];
}

int rodCutProblem_rec(int arr[],int n,int dp[]){
    int max_ ;

    for(int i=2;i<=n;i++){
        max_ = INT_MIN;
        for(int j=0;j<=i/2;j++){
            if(max_ < dp[j] + dp[i-j])
                max_ = dp[j] + dp[i-j];
        }
        dp[i] = max_;
    }

    return dp[n];
}
/// similiar to gfg not verified
int rodCutProblem(int arr[],int n){
    int dp[n+1];
    dp[0] = 0;

    for(int i=1;i<=n;i++)
        dp[i] = arr[i-1];

    return rodCutProblem_rec(arr,n,dp);
}

int longestIncreasingSequence_rec(int arr[],int n,int i){

    int key,x,max_ = 0;
    key = arr[i];

    for(int j=i+1;j<n;j++){
        if(arr[j] > key){
            max_ = max(longestIncreasingSequence_rec(arr,n,j),max_);
        }
    }

    return 1+ max_;
}

int longestIncreasingSequence(int arr[],int n){
    int max_ = 1;

    for(int i=0;i<n;i++)
        max_ =  max(longestIncreasingSequence_rec(arr,n,i),max_);

    return max_;
}

/// gfg verified leet code
int longestIncreasingSequenceDP(int arr[],int n){
    if(n==1)
        return 1;
    int dp[n],temp=0,max_ = 1; /// the min lis can be 1 so max_ is one
    dp[n-1] = 1; /// for last element the lis can be 1 only so

    for(int i=n-2;i>=0;i--){
        temp = 0; /// temp is max length of
        for(int j = i+1;j<n;j++){
            if( arr[j] > arr[i] ){
                temp = max(temp,dp[j]); ///dp[i] is lis for that element we select max of that value
                                        /// from our right
            }
        }
        dp[i] =  max(1,1+temp); /// 1 is for case where i is largest element and one is added to temp to  include ith element
        if(dp[i] > max_)
            max_ = dp[i];
    }
    return max_;
}

/// gfg verified similar to longest increasing sequence
int sumIncreasingSequenceDP(int arr[],int n){
    int dp[n],temp=0,max_ = 0;
    dp[n-1] = arr[n-1];

    for(int i=n-2;i>=0;i--){
        temp = 0;
        for(int j = i+1;j<n;j++){
            if( arr[j] > arr[i] ){
                temp = max(temp,dp[j]);
            }
        }
        dp[i] =  max(arr[i],arr[i]+temp);
        if(dp[i] > max_)
            max_ = dp[i];
    }

    return max_;
}

/// longest common subsequence (lcs)
int lcs(string a,string b,int i1,int i2){

    if(i1 <0 || i2<0)
        return 0;

    if(a[i1] == b[i2])
        return 1 + lcs(a,b,i1-1,i2-1);
    else
        return max( lcs(a,b,i1-1,i2),lcs(a,b,i1,i2-1) );
}

/// leet geek verified the idea is simple if char at index i of str and j of str2 matches we add one to return value else
/// we find max of two possibilities remove one char from str and keep str2 same other possibility remove one char from str2
/// and keep str same.
int lcsDP(string a,string b){
    int n1 = a.length(),n2 = b.length();

    int dp[n1+1][n2+1];

    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            if(i==0 ||j==0)
                dp[i][j] =0;
            else if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    return dp[n1][n2];
}

/// lcs of 3 strings simple extension of above with no special cases
int lcs3Strings(string a,string b,string c){
    int n1 = a.length(),n2=b.length(),n3 = c.length();

    int dp[n1+1][n2+1][n3+1];

    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            for(int k=0;k<=n3;k++){
                if(i==0 ||j==0||k==0)
                    dp[i][j][k] =0;
                else if(a[i-1] == b[j-1] && b[j-1]==c[k-1])
                    dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                else
                    dp[i][j][k] =    max( dp[i][j][k-1], max(dp[i-1][j][k],dp[i][j-1][k]));
            }
        }
    }

    return dp[n1][n2][n3];
}

int editDistanceProblem(string s1,string s2,int i,int j){

    if(i<0 && j<0)
        return 0;

    if(i<0)
        return j+1;

    if(s1[i]==s2[j])
        return editDistanceProblem(s1,s2,i-1,j-1);
    else{
        return 1 + min( editDistanceProblem(s1,s2,i,j-1) ,
             min(editDistanceProblem(s1,s2,i-1,j),editDistanceProblem(s1,s2,i-1,j-1) ) );
    }

}

/// gfg leet verified bottom up approach
int editDistanceProblemDP(string s1,string s2){
    int n1 = s1.length(),n2 = s2.length();
    int dp[n1+1][n2+1];

    int i=0,j=0;

    /// handles base cases
    for(int i=0;i<=n2;i++)
        dp[0][i] = i;    /// case where the s1 is null and s2 has some length i in that case
                        /// the min operation is to insert i char in s1
    for(int i=0;i<=n1;i++)
        dp[i][0] = i;  /// similarly when s2 is null to make them equal min cost is to remove
                       /// i char from s1

    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1]; /// when the char are equal cost of large string is
                                /// equal to cost of smaller string i.e. i-1 and j-1
            else
                dp[i][j] = 1 + min( dp[i][j-1] , min( dp[i-1][j] , dp[i-1][j-1] ) );
                                /// represents
                                ///insert      /// remove          /// replace
        }
    }

    return dp[n1][n2];
}

int minCostPath(int arr[][10],int n,int m,int i=0,int j=0){

    if(i==n-1 && j==m-1)
        return arr[i][j];

    /// cell must be valid
    if(i<n && j<m){
        return arr[i][j] + min( minCostPath(arr,n,m,i,j+1) ,
                   min(minCostPath(arr,n,m,i+1,j) ,
                    minCostPath(arr,n,m,i+1,j+1) ) );
    }
    return INT_MAX;
}

int minCostPathDP_rec(int arr[][10],int dp[][10],int n,int m,int i=0,int j=0){

    if(i==n-1 && j==m-1)
        return arr[i][j];

    if(i<n && j<m){
        if(dp[i][j]==0){
            dp[i][j] =  arr[i][j] + min( minCostPath(arr,n,m,i,j+1) ,
                   min(minCostPath(arr,n,m,i+1,j) ,
                    minCostPath(arr,n,m,i+1,j+1) ) );
        }
        return dp[i][j];
    }
    return INT_MAX;

}
/// same as gold mine problem also niether gfg nor leetcode has verification
int minCostPathDP(int arr[10][10],int n,int m){
    int dp[10][10] = {0};
    return minCostPathDP_rec(arr,dp,n,m);
}


int coinChangeProblem(int coins[],int amount,int n){

    if(amount == 0)
        return 1;

    if(amount <0)
        return 0;

    if(n <= 0 && amount > 0)
        return 0;

    ///cout << "Last statement\n";
            /// including nth coin                          /// excluding nth coin
    return coinChangeProblem(coins,amount - coins[n-1],n) + coinChangeProblem(coins,amount,n-1);
}

/// gfg leet code verified; we are given a certain amount and
/// a certain set of coins we need to determine total no of ways
int coinChangeProblemDP(int coins[],int n,int amount){

    int dp[n+1][amount+1];

    for(int i=0;i<=amount;i++)
        dp[0][i] = 0;
    for(int i=0;i<=n;i++)
        dp[i][0] = 1;

    for(int i=1;i<=amount;i++){
        for(int j=1;j<=n;j++){
            if( i < coins[j-1] ) /// if amount is smaller that coin value copy value from prevoius coin
                dp[j][i] = dp[j-1][i];
            else
                dp[j][i] = dp[j][i-coins[j-1]] + dp[j-1][i];
                           /// including that coin  /// excluding that coin
            /// dp[i][j] stores the total no of ways for amount j using 0...ith coin
            /// dp[j-1][i] no of ways to generate the i amount excluding jth coin
        }
    }

    return dp[n][amount];
}

int bionomialCoff(int n,int k){

    if(k==0 || n==k)
        return 1;

    return bionomialCoff(n-1,k-1) + bionomialCoff(n-1,k);
}

/// gfg verified
int bionomialCoffDP(int n,int k){

    int dp[n+1][k+1];

    for(int i=0;i<=n;i++)
        dp[i][0] = 1;

    for(int i=0;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(i==j)
                dp[i][j] = 1;
            if(i>j)
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    return dp[n][k];
}

int _01KnapsackProblem_rec(int val[],int weight[],int n,int W){

    if(W <=0)
        return 0;

    if(n==0)
        return 0;

    return max( val[n-1] + _01KnapsackProblem_rec(val,weight,n-1,W-weight[n-1]),
    _01KnapsackProblem_rec(val,weight,n-1,W) );
}

/// gfg verified basically same idea of inclusion and exclusion and also recursive approach is
/// simply converted to dp like all other problems take here is to write recursion code well
int _01KnapsackProblemDP(int val[],int weight[],int n,int W){
    int dp[n+1][W+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0||j==0)
                dp[i][j] = 0;
            else if(j - weight[i-1] < 0)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max( val[i-1] + dp[i-1][j-weight[i-1]] , dp[i-1][j] );
        }
    }
    return dp[n][W];
}



int longestBiotonicSequence_rec(int arr[],int n,int i,bool inc = true){

    if(i<0)
        return 0;
    /// whether element should be point of inflection
    if (inc){
        if( i!=n-1 && arr[i] < arr[i+1] ){
            return max( 1 + longestBiotonicSequence_rec(arr,n,i-1,false) , longestBiotonicSequence_rec(arr,n,i-1,true) );
        }
        else
            return 1 + longestBiotonicSequence_rec(arr,n,i-1,inc);
    }
    else{
        if(arr[i] < arr[i+1])
            return 1 + longestBiotonicSequence_rec(arr,n,i-1,inc);
        else
            return longestBiotonicSequence_rec(arr,n,i-1,inc);
    }
}

int longestBiotonicSequence(int arr[],int n){
    int max_ = 0;
    for(int i=n-1;i>=0;i--)
        max_ =  max(max_, longestBiotonicSequence_rec(arr,i+1,i,true));

    return max_;

}

bool maxChainLength_comp(struct val a,struct val b){
    return a.first < b.first;
}

/// slight variation of LIS here we have pairs instead of single no but a pair has property that
/// first element will be smaller and we can rearrange pairs rest is same as LIS
int maxChainLength(struct val p[],int n){
    sort(p,p+n,maxChainLength_comp); ///why sort? because we can rearrange pairs
    int dp[n] = {0};
    int key,temp,max_=0;
    dp[n-1] = 1;

    for(int i=n-2;i>=0;i--){
        key = p[i].second;
        temp = 0;
        for(int j=i+1;j<n;j++){
            if(p[j].first > key)
                temp = max(temp,dp[j]);
        }
        dp[i] = temp + 1;
        if(dp[i] > max_)
            max_ = dp[i];
    }

    return max_;
}

/// we have 3d boxes and we want to create stack of boxes taller as possible with conditon that
/// the lower box base has more base area than higher box boxes having same base can't be used
int boxStackingProblem(int height[],int width[],int length[],int n){

}

/// i is starting index of string and j is ending index
int minInsertionToMakePalindrome(string str,int i,int j){

    if(i>=j)
        return 0;

    if(str[i]==str[j])
        return minInsertionToMakePalindrome(str,i+1,j-1);
    else
        return 1 + min( minInsertionToMakePalindrome(str,i+1,j) ,
                        minInsertionToMakePalindrome(str,i,j-1 ) );

}

/// gfg leet verified
int minInsertionToMakePalindromeDP(string str,int s,int e){
    int dp[e+1][e+1];

    for(int j=0;j<=e;j++){
        for(int i=e;i>=0;i--){
            if(i>=j)
                dp[i][j] = 0;
            else{
                if(str[i]==str[j])
                    dp[i][j] = dp[i+1][j-1];
                else
                    dp[i][j] = 1 + min(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    return dp[0][e];
}

int longestCommonSubstring(string a,string b,int i,int j, int c=0){

    if(i<0 || j< 0)
        return c;

    if(a[i]==b[j])
        return longestCommonSubstring(a,b,i-1,j-1,c+1);
    else
        return max( c , max(longestCommonSubstring(a,b,i-1,j,0),
                            longestCommonSubstring(a,b,i,j-1,0) ) );
}

/// gfg leet verified the basic idea is still converting above code into a dp but prob was with
/// c var in above code doing dp[i][j] = 1+dp[i-1][j-1] for all a[i]==b[j] would cause problem
/// it would become code of longestcommonsubsequence the sol is to do dp[i][j] = 1+dp[i-1][j-1]
/// only if(a[i-2]==b[i-2]) this ensure we are adding to continuity of substring else
/// we start new substring by dp[i][j] = 1;
int longestCommonSubstringDP(string a,string b){
    int max_ = INT_MIN;

   int dp[a.length()+1][b.length()+1];
   for(int i=0;i<=a.length();i++){
        for(int j=0;j<=b.length();j++){
            if(i==0||j==0)
                dp[i][j] = 0;
            else{
                if(a[i-1]==b[j-1]){
                    if(i==1 || j==1)
                        dp[i][j] = 1 + dp[i-1][j-1];
                    else if(a[i-2]==b[j-2]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                    else
                        dp[i][j] = 1;
                }
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }

            if(dp[i][j] > max_)
                max_ = dp[i][j];
        }
   }
   return max_;
}

int diceThrowProblem(int n,int m,int x){
    /// base cases
    if(x==0 && n==0)
        return 1;
    if(x>0 && n==0)
        return 0;

    int ways = 0;
    for(int i=1;i<=m;i++){  /// iterating over all possibilities of m
        if(x>=i)
            ways+=diceThrowProblem(n-1,m,x-i); /// problem reduces to n-1 boxes producing x-i sum
    }
    return ways;
}

/// gfg leet verified just converted above recursion to dp
int diceThrowProblemDP(int n,int m,int x){
    int dp[n+1][x+1] = {0};

    for(int i=0;i<=n;i++){

        for(int j=0;j<=x;j++){
            if(i==0 || j==0){
                if(i==0 && j==0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
            else{
                for(int k=1;k<=m;k++)
                    if(j>=k)
                        dp[i][j]+=dp[i-1][j-k];
            }
        }
    }
    return dp[n][x];
}

/// the function returns what I will get if opponent playes optimally not greedly
int optimalGameStatergy_rec(int arr[],int i,int j,int sum){

    if(j-i==1)
        return min(arr[j],arr[i]);
    /// I have choosen arr[i] now optimalGameStatergy_rec(arr,i+1,j,sum-arr[i]) will return what I
    /// will get this is case for all function calls exept first call in first call it returns
    /// what opponent will get the idea is I will get sum of all coins subtracted the max of
    /// what opponent will get
    return sum - max(arr[i] +optimalGameStatergy_rec(arr,i+1,j,sum-arr[i]),
                     arr[j] +optimalGameStatergy_rec(arr,i,j-1,sum-arr[j]) );
}

int optimalGameStatergy(int arr[],int n){
    int sum = 0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    return sum -optimalGameStatergy_rec(arr,0,n-1,sum);
}

/// suprisingly it works gfg verified
int optimalGameStatergyDP(int arr[],int n){
    int dp[n][n] = {0};

    int sum[n+1],temp=0;
    sum[0] = 0;
    for(int i=1;i<=n;i++){
        temp+=arr[i-1];
        sum[i] = temp;
    }

    for(int j=1;j<n;j++){
        for(int i=n-2;i>=0;i--){
            if(j>i){
                if(j-i==1)
                    dp[i][j] = min(arr[i],arr[j]);
                else
                    dp[i][j] = sum[j+1]-sum[i] - max(arr[i] + dp[i+1][j] , arr[j] + dp[i][j-1]);
            }
        }
    }
    return sum[n]- dp[0][n-1];
}

bool inDictinary(string dictionary[],int n,string str,int s,int e){
    string key;
    for(int i=0;i<n;i++){
        key = dictionary[i];
        if(key.length() != e-s+1)
            continue;
        else{
            int j,k;
            for(j=s,k=0;j<=e;j++,k++)
                if(str[j]!=key[k])
                    break;
            if(k==key.length())
                return true;
        }
    }
    return false;
}

/// gfg verified
bool wordBreakingProblem(string dictionary[],int n,string str,int s,int e){

    if(inDictinary(dictionary,n,str,s,e))
        return true;
    else{
        for(int i=s;i<=e;i++){
            if(inDictinary(dictionary,n,str,s,i))
                if(wordBreakingProblem(dictionary,n,str,i+1,e))
                    return true;
        }
        return false;
    }
}

/// leet code verified
bool wordBreakingProblemDP(string dictionary[],int dicSize,string str){

    int n = str.length();
    bool dp[n] = {0}; /// this guys stores whether string upto i is in dictionary or not

    for(int i=0;i<n;i++){
        /// check whether sub string up to i is in dictionary or not
        if(dp[i]==0 && inDictinary(dictionary,dicSize,str,0,i))
            dp[i] = 1;
        /// if in dictionary then check for rest of string
        if(dp[i]==1){

            for(int j=i+1;j<n;j++){
                if(dp[j]==0 && inDictinary(dictionary,dicSize,str,i+1,j))
                    dp[j] = 1;
            }
        }
    }

    return dp[n-1];

}


/// perfectly fine logic
bool isInterleavedofTwo_rec(string a,string b,string c,int i,int j,int k){

    if(i<0 && j<0 && k<0)
        return true;
    if(i<0){
        if(c[k]==b[j])
            return isInterleavedofTwo_rec(a,b,c,i,j-1,k-1);
        return false;
    }
    if(j<0){
        if(c[k]==a[i])
            return isInterleavedofTwo_rec(a,b,c,i-1,j,k-1);
        return false;
    }

    if(c[k]==a[i] || c[k]==b[j]){
        if (a[i]==b[j])
            return isInterleavedofTwo_rec(a,b,c,i-1,j,k-1) || isInterleavedofTwo_rec(a,b,c,i,j-1,k-1);
        else if(c[k]==a[i])
            return isInterleavedofTwo_rec(a,b,c,i-1,j,k-1);
        else
            return isInterleavedofTwo_rec(a,b,c,i,j-1,k-1);
    }
    else
        return false;
}

bool isInterleavedofTwo(string a,string b,string c){
    return isInterleavedofTwo_rec(a,b,c,a.length()-1,b.length()-1,c.length()-1);
}

/// seems big it's nothing but the implementation of above recursive code there are lot of cases to
/// handle that's why it's kind of big we start from 0 index in all strings and the kth char of c
/// must match with either of char of string if does return what smaller string would return else false
/// the problem occurs where all char of 3 strings are same in that case we take or of both possibilities
bool isInterleavedofTwoDP_rec(string a,string b,string c,int i,int j,int k,int dp[][101]){
    if(dp[i][j] == -1){
        /// case where all three strings are used up
        if(i>=a.length() && j>=b.length() && k>=c.length()){
            dp[i][j] = true;
            return dp[i][j];
        }
        if(i>=a.length()){  /// a string is used up
            if(c[k]==b[j]){
                dp[i][j] =  isInterleavedofTwoDP_rec(a,b,c,i,j+1,k+1,dp);
                return dp[i][j];
            }
            else{
                dp[i][j] = false;
                return dp[i][j];
            }
        }
        if(j>=b.length()){  /// b string is used up
            if(c[k]==a[i]){
                dp[i][j] = isInterleavedofTwoDP_rec(a,b,c,i+1,j,k+1,dp);
                return dp[i][j];
            }
            else{
                dp[i][j] =  false;
                return dp[i][j];
            }
        }

        if(c[k]==a[i] || c[k]==b[j]){
            if (a[i]==b[j]){
                dp[i][j] = isInterleavedofTwoDP_rec(a,b,c,i+1,j,k+1,dp) || isInterleavedofTwoDP_rec(a,b,c,i,j+1,k+1,dp);
                return dp[i][j];
            }
            else if(c[k]==a[i]){
                dp[i][j] = isInterleavedofTwoDP_rec(a,b,c,i+1,j,k+1,dp);
                return dp[i][j];
            }
            else{
                dp[i][j] = isInterleavedofTwoDP_rec(a,b,c,i,j+1,k+1,dp);
                return dp[i][j];
            }
        }
        else{
            dp[i][j] = false;
            return dp[i][j];
        }
    }
    return dp[i][j];
}
/// leet gfg verified
bool isInterleavedofTwoDP(string a,string b,string c){
    if (c.length() != a.length()+b.length())
            return 0;
    int dp[101][101];

    for(int i=0;i<=a.length();i++)
        for(int j=0;j<=b.length();j++)
            dp[i][j] = -1;

    return isInterleavedofTwoDP_rec(a,b,c,0,0,0,dp);

}

int longestArithmeticProgression_rec(int arr[],int n,int i,int inc){

    for(int j=i+1;j<n;j++){
        if(arr[j]==arr[i]+inc){
            return 1 +longestArithmeticProgression_rec(arr,n,j,inc);
        }
    }
    return 0;

}
/// suprisingly gfg leet code verified o(n^3) solution.
int longestArithmeticProgression(int arr[],int n){
    int max_ = INT_MIN;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++)
            max_ = max(max_,2+longestArithmeticProgression_rec(arr,n,j,arr[j]-arr[i]));
    }
    return max_;
}

/// problem is of cutting rod of n length into integer pieces and calculate product of length of pieces
/// and maximizing the product conditions are length is greater than 1 and 1 cut is compulsory
int maxProductCut(int n){
    /// base cases
    if(n<2)
        return 0;
    if(n==2)
        return 1;
    int max_ = 0;
    for(int i=1;i<=n/2;i++) /// we chop piece of i length and and process rest of rod it's max of
    /// length of remaining rod n-i or maxProduct of remaining rod.
        max_ = max(max_,i*max(n-i,maxProductCut(n-i)));

    return max_;
}

int maxProductCutDP_rec(int dp[],int n){
    if(n<2)
        return 0;
    if(n==2)
        return 1;
    int max_ = 0;
    for(int i=1;i<=n/2;i++){
        if(dp[n-i]==-1){
            dp[n-i] = maxProductCutDP_rec(dp,n-i);
        }
        max_ = max(max_,i*max(n-i, dp[n-i] ));
    }

    return max_;
}
/// leetcode verified the code is just implementation of above recursive code
int maxProductCutDP(int n){
    int dp[n+1];
    for(int i=3;i<=n;i++)
        dp[i] = -1;
    dp[0] = dp[1] = 0;
    dp[2] = 1;

    return maxProductCutDP_rec(dp,n);
}

/// this is very interesting problem the standard way of solving can't be implemented as a program so we have taken another
/// way we basically parathesis the given chain in different ways and return min of those ways like given chain is ABCD so
/// diff ways are (A)(BCD); (AB)(CD) ; (ABC)(D) it's diff then the first way u thought which can't be implemented easily
int matrixChainMultiplation(int matrix[],int i,int j){
    if(i==j)
        return 0;
    int min_ = INT_MAX,count;
    for(int k=i;k<j;k++){
        count = matrix[i-1]*matrix[k]*matrix[j] /// this is dimensions of last matrix that would be mul during current set
        /// of parathesis
        + matrixChainMultiplation(matrix,i,k) /// the solution of one of matrix chain inside parathesis same goes for
         + matrixChainMultiplation(matrix,k+1,j); /// this one dry run is very imp here

        if(count < min_)
            min_ = count;
    }
    return min_;
}

int matrixChainMultiplationDP_rec(int matrix[],int dp[][100],int i,int j){
    if(i==j)
        return 0;
    int min_ = INT_MAX,count;

    for(int k=i;k<j;k++){
         if(dp[i][k]==-1){
            dp[i][k] = matrixChainMultiplationDP_rec(matrix,dp,i,k);
         }
         if(dp[k+1][j]==-1){
            dp[k+1][j] = matrixChainMultiplationDP_rec(matrix,dp,k+1,j);
         }
        count = matrix[i-1]*matrix[k]*matrix[j]
        + dp[i][k] + dp[k+1][j];

        if(count < min_)
            min_ = count;
    }
    return min_;
}
/// gfg verified the problem is simply conversion of above recursive code
int matrixChainMultiplationDP(int matrix[],int n){
    int dp[100][100];

    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            dp[i][j] = -1;

    return matrixChainMultiplationDP_rec(matrix,dp,1,n-1);
}

bool isPalindrome(string str,int i,int j){
    if(i==j)
        return true;
    int k,len=(j-i+1)/2;
    for(k=i;k<i+len;k++){
        if(str[k]!=str[j-k+i])
            break;
    }
    if(k==i+len)
        return true;
    else
        return false;
}
/// we calculate the cost of all partitions of string basically we divide the string into a non-palindrome and palindrome
/// sections then we add one to the cut then we recursively do same thing for non-pali section if whole string or section
/// is palindrome we return 0; though we can improve on the isPalindrome function using dp
int palindromePartition(string str,int i,int j){

    if(isPalindrome(str,i,j))
        return 0;
    int min_ = INT_MAX,k,temp;
    for(k=j;k>=1;k--){
        if(isPalindrome(str,k,j)){
            temp = 1+ palindromePartition(str,i,k-1);
            if(temp < min_)
                min_ = temp;
        }
    }
    return min_;
}

int palindromePartitionDP_rec(string str,int i,int j,int dp[],int n){

    if(isPalindrome(str,i,j))
        return 0;
    int min_ = INT_MAX,k,temp;
    for(k=j;k>=1;k--){
        if(isPalindrome(str,k,j)){
            if(dp[k-1]==-1){
                dp[k-1] = palindromePartitionDP_rec(str,i,k-1,dp,n);
            }
            temp = 1+ dp[k-1];
            if(temp < min_)
                min_ = temp;
        }
    }
    return min_;
}
/// gfg verified
int palindromePartitionDP(string str){
    int len = str.length();
    int dp[len];
    dp[0] = 0;
    for(int i=1;i<len;i++)
        dp[i] = -1;
    return palindromePartitionDP_rec(str,0,len-1,dp,len);
}

/// this approach works but not optimized DP of this also slow. your original approach
int _longestPalindromeSequence(string str,int s,int e){ /// s and e are start and end index of string
    if(s==e)
        return 1;
    if(s>e)
        return 0;
    int max_ = 1;

    for(int i=s;i<e;i++){ /// pick a char from left
        for(int j=e;j>i;j--){ /// search if from right
            if(str[i]==str[j]) /// if found add 2 to length and process string in b/w two char
                max_ = max(max_,2+_longestPalindromeSequence(str,i+1,j-1));
        }
    }

    return max_;
}

int longestPalindromeSequence(string str,int i,int j){

    if(i>j)
        return 0;
    if(i==j)
        return 1;

    if(str[i]==str[j])
        return 2+longestPalindromeSequence(str,i+1,j-1);
    else
        return max( longestPalindromeSequence(str,i+1,j), longestPalindromeSequence(str,i,j-1));
}

/// leet code verified
int longestPalindromeSequenceDP(string str){
    int len = str.length();
    int dp[len][1000] = {0};

    for(int j=0;j<len;j++){
        for(int i=j;i>=0;i--){
            if(i==j)
                dp[i][j] = 1;
            else if(str[i]==str[j])
                dp[i][j] = 2 + dp[i+1][j-1];
            else
                dp[i][j] = max( dp[i+1][j],dp[i][j-1]);
        }
    }

    return dp[0][len-1];
}

/// we have two pointers i and j initially pointing at last index if the char at index i and j match and i!=j then we add
/// one to return value for all other cases we return max of foo(i-1,j) and foo(i,j-1)
int longestRepeatingSequence(string str,int i,int j){

    if(i<0 || j<0 ) /// base case
        return 0;

    if( str[i] == str[j] && i!=j )
        return 1 + longestRepeatingSequence(str,i-1,j-1);
    if( (str[i] == str[j] && i==j) || str[i]!=str[j] )
        return max( longestRepeatingSequence(str,i-1,j) , longestRepeatingSequence(str,i,j-1));

}

/// gfg verified
int longestRepeatingSequenceDP(string str){
    int len = str.length();
    int dp[len+1][len+1];

    for(int j=0;j<=len;j++){
        for(int i=0;i<=len;i++){
            if(i==0||j==0)
                dp[i][j] = 0;
            else if(str[i-1]==str[j-1]  && i!=j)
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[len][len];
}

/// gfg verified.  the statement of question is confusing the statement let someone thin that only two fences are allowed to
/// have same color but any no of pairs can have same color given the same color isn't for more than two adjacent fences
/// so for n = 4 RRBB and BBRR are also valid the direct formula for given n and k is hard to find we can however do it recursively
/// let say we already know answer for given n-2 and n-1 and we want to calculate for n. the last fence is added to n-1 fences
/// so there are two possibilities last and 2nd last have same color other being having diff color. if they have same color
/// then total ways are diff[i-1]{ no of ways of previous arrangement having diif color } why? because if previous arrangement
/// had same color and this arrangement also have same color then there would be 3 fences having same color hence same[i] has to be
/// diff[i-1] and for diff[i] we can see that last added fence is allowed to have k-1 colors so diff[i] would be total[i-1]*(k-1)
int paintFencingProblem(int n,int k){
    int MOD = 1000000007;
    /// base cases
    if(n==1)
        return k;
    if(n==2)
        return k*k;

    long long dp[n+1];
    dp[1] = k;
    dp[2] = k*(k-1);

    for(int i=3;i<=n;i++){
        dp[i] = ( (( dp[i-1] + dp[i-2] )%MOD)*(k-1) )%MOD ;
    }

    return (dp[n] + dp[n-1])%MOD;
}
/// gfg verified it's O(n) solution the idea is to use dp what we are doing actually in dp we are storing the maxValue of
/// sequence with that element included we are checking only i+2 and i+3 values because i+1 can't be part of solution and
/// checking for just i+2 and i+3 covers whole array from i to n-1
long long maxSubsequenceSumNoElementsAdjacent(long long arr[],int n){

    if(n==1)
        return arr[0];

    long long dp[n],temp_,max_;
    dp[n-1] = arr[n-1];
    dp[n-2] = arr[n-2];
    max_ = max(dp[n-1],dp[n-2]);

    for(int i=n-3;i>=0;i--){
        temp_ = 0;
        if(i+2<n)
            temp_ = max(temp_,dp[i+2]);
        if(i+3<n)
            temp_ = max(temp_,dp[i+3]);

        dp[i] = temp_ + arr[i];
        max_ = max( dp[i], max_ );
    }
    return max_;
}
/// gfg verified basically we need to maximize the sum of pairs such that the diff bw pairs are less than k a element once
/// used can't be used again. So idea is to sort array such that we would get larger elements first we keep a array to determine
/// whether the element has been used or not
int maxSumofDisjointPairsWithSpecificDiff(int arr[],int n,int k){
    sort(arr,arr+n);
    bool dp[n]; int sum = 0;
    for(int i=0;i<n;i++)
        dp[i] = 0;
    for(int i=n-1;i>=1;i--){
        if(!dp[i]){  /// if element has not been used  and if sum b/w element and next one is less than k we add both
            if( arr[i] - arr[i-1] < k ){
                sum = sum + arr[i] + arr[i-1];
                dp[i] = dp[i-1] = 1;
            }
        }
    }
    return sum;
}

/// gfg verified the q is so simple
int maxSumByBreakingNumber(int n){
    if(n<=11)
        return n;
    return max( n, maxSumByBreakingNumber(n/2) + maxSumByBreakingNumber(n/3) + maxSumByBreakingNumber(n/4));
}

int minJumpsToReachEnd(int arr[],int n,int i=0){
    if(i>=n)
        return INT_MAX;
    if(i==n-1)
        return 0;
    int min_ = INT_MAX;

    for(int j=1;j<=arr[i];j++)
        min_ = min(min_,minJumpsToReachEnd(arr,n,i+j));

    return min_ +1;

}
/// gfg verified simple problems find the min of all possibilities
int minJumpsToReachEndDP(int arr[],int n){
    int dp[n];int min_;
    dp[n-1] = 0;         /// base case

    for(int i=n-2;i>=0;i--){
        min_ = INT_MAX;
        for(int j=1;j<=arr[i];j++){  /// iterate through all possibilities
            if(i+j < n){             /// if possible
                min_ = min(min_,dp[i+j]);  /// find min of all
            }
        }
        if(min_ == INT_MAX)
            dp[i] = INT_MAX;
        else
            dp[i] = 1 + min_;
    }

    return dp[0];
}

/// in this q i index represents the weight of ith item in 1 indexing and arr[i] represents the cost we have to min cost
/// for a given W arr[i] = -1 means item of i weight is not present
int minCostToFillBags(int arr[],int n,int W){
    /// base case
    if(W==0)
        return 0;
    int min_ = INT_MAX,op1;
    for(int i=0;i<n;i++){ /// try all items for a specific weight
        if(W-(i+1)>=0 && arr[i]!=-1){ /// if W is equal or greater than weight of current item and item is available
            op1 = minCostToFillBags(arr,n,W-(i+1));
            if(op1 == -1)
                min_ = min(min_, INT_MAX);
            else
                min_ = min(min_, op1 + arr[i]);
        }
    }
    if(min_ == INT_MAX)
        return -1;
    return min_;  /// return min of all possibilities
}

/// gfg verified
int minCostToFillBagsDP(int arr[],int n,int W){
    int dp[W+1],min_;
        dp[0] = 0;

    for(int i=1;i<=W;i++){
        min_ = INT_MAX;
        for(int j=0;j<n;j++){
            if(i-(j+1)>=0 && arr[j]!=-1){
                if(dp[i-(j+1)] == -1)
                    min_ = min(min_,INT_MAX);
                else
                    min_ = min(min_,arr[j] + dp[i-(j+1)] );
            }
        }
        if(min_ == INT_MAX)
            dp[i] = -1;
        else
            dp[i] = min_;
    }

    return dp[W];
}

int tileStackingProblem_rec(int n,int k,int m,int tiles[],int i=0,int pre=INT_MAX){

    if(i==n)
        return 1;
    int result = 0;
    for(int j=1;j<=m;j++){
        if( tiles[j-1] <k && j<=pre ){
            tiles[j-1]++;
            result +=tileStackingProblem_rec(n,k,m,tiles,i+1,j);
            tiles[j-1]--;
        }
    }

    return result;
}

int tileStackingProblem(int n,int k,int m){

    int tiles[m] = {0};

    return tileStackingProblem_rec(n,k,m,tiles);

}

/// this is a recursive approach the dp one has to be achieved by finding longest palindromic subsequence and subtracting
/// length of LPS from length of string and determine <=k ? or not
bool isKPalindrome(string str,int k,int s,int e){

    if(k>=0 && s==e)
        return 1;
    if(k <0)
        return 0;


    if(str[s]==str[e])
        return isKPalindrome(str,k,s+1,e-1);
    else
        return isKPalindrome(str,k-1,s+1,e) || isKPalindrome(str,k-1,s,e-1);
}



int shortestCommonSuperSequence(string str1,string str2,int i1=0,int i2=0){

    if(i1==str1.length() || i2==str2.length())
        return i1==str1.length() ? str2.length() - i2 : str1.length()-i1;


    if(str1[i1]==str2[i2])
        return 1 +shortestCommonSuperSequence(str1,str2,i1+1,i2+1);

    else
        return 1 +min(  shortestCommonSuperSequence(str1,str2,i1+1,i2) ,
                   shortestCommonSuperSequence(str1,str2,i1,i2+1) );
}

/// gfg verified
int shortestCommonSuperSequenceDP(string str1,string str2){
    int n1 = str1.length(),n2 = str2.length();
    int dp[n1+1][n2+1];

    for(int j=n2;j>=0;j--){
        for(int i=n1;i>=0;i--){

            if(i==n1||j==n2){
                dp[i][j] = i==n1 ? n2-j : n1-i;
            }

            else if(str1[i]==str2[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else{
                dp[i][j] = 1 + min( dp[i+1][j],dp[i][j+1]);
            }
        }
    }

    return dp[0][0];
}


int main() {
    int arr[] = {20, 10, 4, 50, 100};
    string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
                           "icecream","and","go","i","like","ice","cream"} ,str = "abcdeca";
    int n = sizeof(arr)/sizeof(arr[0]);
    int dicsize =sizeof(dictionary)/sizeof(dictionary[0]);
    int len = str.length();

    cout << shortestCommonSuperSequenceDP("AGGTAB","GXTXAYB");
    return 0;
}
