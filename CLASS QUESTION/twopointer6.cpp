//Q. Given an array of integers and a integer k, find the number of unordered pairs
//having the sum equal to k. eg: ip: arr=[1,2,3,4], k = 5 output: 2
//explanation: 1+4=5, 2+3 = 5→ 2 pairs
//Note :- all the elements of the array are distinct.
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
    for (auto &x : v) {cin >> x;}
    int l = 0, r = n-1;
    int cnt = 0;
    while (l < r)
    {
        int sum = v[l] + v[r];
        if (sum < k) {l++;}
        else if (sum > k) {r--;}
        else {cnt++; l++; r--;} // yaha pe l++ aur r-- isliye kie as cnt++ hua hoga means
        //v[l] + v[r] = k mila hoga, ab dono mese koi bhi change hua to sum k nahi hoga
        //according to the equation so dono ko change kar die as in that case possibility is there.
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