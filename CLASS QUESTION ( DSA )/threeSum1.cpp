//in this question we are printing the triplet in the array whose sum is zero.
//this is the brute force approach , TC = O(n^3)
//video number 36.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define pb push_back

void VivekTiwary_1092()
{
    int n;
    cin >> n;
    int arr[n];
    for (auto &x : arr) {cin >> x;}
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                  vector<int> temp = {arr[i], arr[j], arr[k]};
                  sort(temp.begin(), temp.end());
                  st.insert(temp);  
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    for (auto &x : ans) { for (auto &y : x) {cout << y << " ";} cout << "\n";}
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