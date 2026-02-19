//here we want to reverse an array using recursion
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"

//see from line 40 we could have also written the function using one parameter i.
vector<int> a;
void f(int l, int r)
{
    if (l >= r) {return;}
    swap(a[l], a[r]);
    f(l+1, r-1);
}
void VivekTiwary_1092()
{
    int n; cin >> n;
    a.resize(n);
    for (auto &x : a) {cin >> x;}
    f(0, n-1);
    for (auto x : a) {cout << x << " ";}
    cout << endl;
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

// vector<int> a;
// int n;
// void f(int i)
// {
//     if (i >= n/2) {return;}
//     swap(a[i], a[n-1-i]);
//     f(i+1);
// }
// void VivekTiwary_1092()
// {
//     cin >> n;
//     a.resize(n);
//     for (auto &x : a) {cin >> x;}
//     f(0);
//     for (auto x : a) {cout << x << " ";}
//     cout << endl;
// }