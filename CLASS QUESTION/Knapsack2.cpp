// The same problem in dp6.cpp has to be solved using dp here due to the high constraints.
// Constraints :- N <= 1𝑒2 , 𝑊𝑖 <= 1𝑒5 , 𝑋 <= 1𝑒5, now time complexity of (n*2^n) wont work
// hence we will solve it in N*X.

// Learning :- in dp states can be determined using the constraints, yaha w aur x ka state
// nahi ho sakta hai as they would not pass in one sec but n aur x ka ho sakta hai...

// state of dp : dp[i][j] = 1 {if first i objects se we could select a subset with sum j}
//                        = 0 {otherwise}
// Transition : not taken    | taken
//  dp [i][j] = dp[i − 1][j] | dp[i − 1][j − 𝑤[i]]  ---- A
// in A , dp[i − 1][j] ko not take kar rahe hai as i-1 tak j sum bana lie hai(iska value 1
// hoga in this case , but nahi bana hoga toh zero bhi ho sakta hai...), so ith weight,aur
// dp[i − 1][j − 𝑤[i]] ko take kar rahe hai as i-1 tak hamlog j-w[i] weight banaye hai, so
// so, i pe w[i] ko leke j sum banjayega....

// Final answer : dp[n][x];
// Note : We are using 1 based indexing such that dp[0][0] means - using the first 0
// element can we make a sum of 0. That means - using no elements can we make a sum of 0.
// and the answer is yes.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

//Time complexity :  O(N*X)
//Space complexity : O(N*X) 

bool dp[(int)1e2 + 1][(int)1e5 + 1];

bool is_possible(int num_obj, vector<int> &weights, int reqsum)
{
    dp[0][0] = 1; // base case
    for (int i = 1; i <= num_obj; i++)
    {
        for (int j = 0; j <= reqsum; j++)
        {
            dp[i][j] = dp[i - 1][j]; // not taken
            if (j - weights[i - 1] >= 0)
            {
                dp[i][j] |= dp[i - 1][j - weights[i - 1]]; // taken
            }      
        }
    }
    return dp[num_obj][reqsum];
}
void VivekTiwary_1092()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (is_possible(n, a, x)) {cout << "YES\n";}
    else {cout << "NO\n";}
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        VivekTiwary_1092();
    }
    return 0;
}