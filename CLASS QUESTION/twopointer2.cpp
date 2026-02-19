//https://cses.fi/problemset/task/1641 :- Question link
//solved using two pointer appraoch.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

void VivekTiwary_1092()
{
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].f;
        v[i].s = i;
    }
    sort(v.begin(), v.end());
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int sl = x - v[i].f; //sl = sumleft 
        int l = i+1; int r = n-1;
        while (l < r)
        {
            int sum = v[l].f + v[r].f;
            if (sum == sl) 
            {
                ans.pb(v[i].s); ans.pb(v[l].s); ans.pb(v[r].s);
                break;
            }
            else if (sum < sl) { l++; }
            else { r--; }
        }
        if (ans.size() != 0) { break; }
    }
    sort(ans.begin(), ans.end());
    if (ans.size() != 0)
    {
        cout << ans[0] + 1 << " " << ans[1] + 1 << " " << ans[2] + 1;
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
    
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