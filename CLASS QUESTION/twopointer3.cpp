//Question Link :- https://codeforces.com/contest/279/problem/B
//TC = O(n)
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

void VivekTiwary_1092()
{
    int n, t;
    cin >> n >> t;
    int a[n];
    for (auto &x : a) {cin >> x;}
    int sum = 0, ans = 0;
    int l = 0;
    for (int r = 0; r < n; r++)
    {
        sum = sum + a[r];
        while (sum > t) { sum -= a[l]; l++; } //ye while loop max n bar chalega aur for loop bhi
        ans = max(ans, r-l+1);                //so in total n + n = 2n times hi max chal sakta hai
    }                                         //according to the logic of the code, so O(n).
    cout << ans;
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