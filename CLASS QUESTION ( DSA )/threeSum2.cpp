//in this we are trying to replicate what we did in threeSum1.cpp but we are trying to do this in 
//O(n^2). for this we are using hash array, it is video number 36.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define pb push_back
//it is a better approach but the optimal approach for this is in threeSum3.cpp
void VivekTiwary_1092()
{
    int n;
    cin >> n;
    int arr[n];
    for (auto &x : arr) {cin >> x;}
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        set<int> hsh;
        for (int j = i+1; j < n; j++)
        {
            int req = -(arr[i] + arr[j]);
            if (hsh.find(req) != hsh.end())
            {
                vector<int> temp;
                temp = {arr[i], arr[j], req};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hsh.insert(arr[j]);
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