//Given a sorted array, which has been left rotated k times. (eg- initially 
//the array is 1 2 3 4 5.. after 1 left rotation it becomes 5 1 2 3 4.. now if k=2 ,. 
//the array becomes 5 4 1 2 3. U are given this array in the question). The task is to 
//find k.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

void VivekTiwary_1092()
{
    int n;  //agar  4 5 1 2 3 hai toh 2 bar rotate hua hai, so ham hamseha 0 index wala value
    cin >> n; //se compare karte hai ki usse chota phela value konsa hai, uska index hi ans hoga
    vector<int> v(n);
    for (auto &x : v) {cin >> x;}
    int l = 1, r = n - 1;
    int ans = 0;
    while (l <= r)
    {
        int m = l + (r - l)/2;
        if (v[m] < v[0]) {ans = m; r = m - 1;}
        else {l = m + 1;}
    }
    if (!(v[n -1] < v[0])) {cout << 0 << "\n";}
    else {cout << ans << "\n";}
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