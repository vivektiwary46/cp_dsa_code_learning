#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

int n; 
vector<int> v;
const int MAX = 1e4;
int dp[MAX+1][MAX+1];

int f(int l, int r)
{
    if (l == r) {return 0;}
    if (dp[l][r] != -1) {return dp[l][r];}
    dp[l][r] = 1e9;
    for (int k = l; k < r; k++)
    {
        dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r] + v[l-1]*v[k]*v[r]);
    }
    return dp[l][r];
}
void VivekTiwary_1092()
{
   cin >> n;
   v.resize(n);
   for (int i = 0; i < n; i++) {cin >> v[i];}
   cout << f(0, n-1); 
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    int t = 1;
    while (t--)
    {
        VivekTiwary_1092();
    }
    return 0;
}