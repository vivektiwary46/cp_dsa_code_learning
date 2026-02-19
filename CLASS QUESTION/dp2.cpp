//Here we are writting the same code as dp1.cpp but with the help of iteration/tabulation.
//hence it is iterative dp or tabulation dp.
//This is an example of bottom up approach.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"

//TC :- O(N)
//SC :- O(N) -> this space can also be optimized to O(1) -> see dp2.cpp of class question dsa.
void VivekTiwary_1092()
{
    int n; 
    cin >> n;
    vector<int> dp(n+1, -1);
    dp[0] = 0; dp[1] = 1; //followed 0 based indexing.
    for (int i = 2; i < n+1; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--)
    {
        VivekTiwary_1092();
    }
    return 0;
}