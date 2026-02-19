//This is for vectors
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

bool customSort(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first) 
    {
        return a.second < b.second; //agar first dono ka same hua toh this syntax will arrange it in ascending order.
    } // and a.second > a.first will arrange in descending order.
    return a.first < b.first; //this will arrange the pairs in ascending order, aur a.first > a.second will arrange in descending order.
}

void VivekTiwary_1092()
{
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), customSort);
    for (int i = 0; i < n; i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
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