#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"

void VivekTiwary_1092()
{
    int n; cin >> n;
    vector<int> p(n+1);
    p[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    vector<int> vis(n+1);
    vector<int> ans(n+1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vector<int> curr;
            while (!vis[i])
            {
                curr.pb(i);
                vis[i] = 1;
                i = p[i];
            }
            for (auto ele : curr) ans[ele] = curr.size();
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
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