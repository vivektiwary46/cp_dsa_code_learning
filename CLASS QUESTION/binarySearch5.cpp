#include<bits/stdc++.h>
using namespace std;
#define int long long

void VivekTiwary_1092()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) {cin >> x;}
    sort(v.begin(), v.end());
    int k;
    cin >> k;
    while (k--)
    {
        int l, r;
        cin >> l >> r;
        auto itl = lower_bound(v.begin(), v.end(), l);
        auto itr = upper_bound(v.begin(), v.end(), r);
        cout << itr - itl << " ";
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