#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"

vector<int> arr;
vector<vector<int>> res;


void f(int ind, vector<int> temp, map<int, int> mp)
{
    int flag = 0;
    for (int j = 0; j < mp.size(); j++)
    {
        if (mp[j] == 0) 
        {
            res.pb(temp);
            flag = 1; 
            break; 
        }
    }
    if (flag == 0) {res.pb(temp); return;}

    for (int i = ind; i < arr.size(); i++)
    {
        if (mp[i] != 1)
        {
            temp.pb(arr[i]);
            mp[i] = 1;
            f(i+1, temp, mp);
            temp.pop_back();
            mp[i] = 0;
        }
    }

}
void VivekTiwary_1092()
{
    int n; cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {cin >> arr[i];}
    vector<int> temp;
    map<int, int> mp;
    for (int i = 0; i < arr.size(); i++) {mp[i] = 0;}
    f(0, temp, mp);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << "\n";
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