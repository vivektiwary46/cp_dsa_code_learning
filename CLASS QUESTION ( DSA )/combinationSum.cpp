#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"

vector<int> arr;
int n;
vector<vector<int>> res;

void f(int i, int tar, vector<int> temp)
{
    if (tar == 0)
    {
        res.pb(temp);
        return;
    }
    if (i == n || tar < 0)
    {
        return;
    }

    //take
    temp.pb(arr[i]);
    tar -= arr[i];
    f(i, tar, temp);

    //not take
    temp.pop_back();
    tar += arr[i];
    f(i+1, tar, temp);

}
void VivekTiwary_1092()
{
    cin >> n; arr.resize(n);
    for(int i = 0; i < n; i++) {cin >> arr[i];} 
    int tar; 
    cin >> tar;
    vector<int> temp;
    f(0, tar, temp);

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