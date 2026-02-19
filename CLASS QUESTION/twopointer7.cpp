//The same question as 2pointer6.cpp just that yaha elements can be duplicate, we just need to
//state number of pairs with sum k.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

void VivekTiwary_1092()
{
    int n, k; cin >> n >> k;
    vector<int> v(n);
    map<int, int> f;
    for (auto &x : v) {cin >> x; f[x]++;}
    vector<int> b;
    int cnt = 0;
    for (auto &i : f)
    {
        b.pb(i.f); //b mein v ke sare distinct elments store kar liye hai.
        int num = i.f;
        int freq = i.s;
        if (num + num == k) {cnt += freq * (freq - 1) / 2;} //if k = 6 aur 3 do bar appear kar raha ho so this case will be handeled here.
    }
    int l = 0, r = b.size() - 1;
    while (l < r) //this can be done now as b mein sare distinct element hai aur we know their frequency also.
    {
        int sum = b[l] + b[r];
        if (sum > k) {r--;}
        else if (sum < k) {l++;}
        else 
        {
            cnt += f[b[l]] * f[b[r]];
            l++; r--; //same logic as given in 2pointer6.cpp
        }
    }
    cout << cnt;
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