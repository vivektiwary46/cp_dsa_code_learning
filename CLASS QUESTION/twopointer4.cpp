//Question Link :- https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/B
//TC = O(n)- for the logic of time complexity it is just as same in 2pointer3.cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

void VivekTiwary_1092()
{
    int n, s;
    cin >> n >> s;
    int a[n];
    for (auto &x : a) {cin >> x;}
    int l = 0, sum = 0, ans = 1e5+1;
    for (int r = 0; r < n; r++)
    {
        sum = sum + a[r];
        while (sum -a[l] >= s) { sum -= a[l]; l++;}
        if (sum >= s) {ans = min(ans, r-l+1);}
    }
    if (ans == 1e5+1) {cout << -1;}
    else {cout << ans;}
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