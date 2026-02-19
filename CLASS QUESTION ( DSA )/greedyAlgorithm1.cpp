//Question LinK :- https://leetcode.com/problems/assign-cookies/description/
//Video Link :- https://www.youtube.com/watch?v=DIX2p7vb9co&list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&index=284
//Time complexity = O(nlog(n)) + O(mlog(m)) + O(m);
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define pb push_back

void VivekTiwary_1092()
{
    int n;
    cin >> n;
    vector<int> g(n);
    for (auto &x : g) { cin >> x; }
    int m;
    cin >> m;
    vector<int> s(m);
    for (auto &x : s) { cin >> x; }
    sort(g.begin(), g.end());  sort(s.begin(), s.end());
    int l = 0, r = 0;
    while (l < m && r < n)
    {
        if (g[r] <= s[l]) { r = r + 1; }
        l = l + 1;
    }
    cout << r;
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