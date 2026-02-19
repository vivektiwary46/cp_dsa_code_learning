//We need to do the same as in twoSum1.cpp but in a better time complexity.
//Time Complexity :- O(N) -> if the map works in O(N) and O(logN) is map works in O(logN).
//Note that unordered map always works in O(N).
//Space Complexity is O(N).
#include <bits/stdc++.h>
using namespace std;
#define int long long

void VivekTiwary_1092()
{
    int n;
    cin >> n;
    int arr[n];
    for (auto &x : arr)
    {
        cin >> x;
    }
    int target;
    cin >> target;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int a = arr[i];
        int more = target - a;
        if (mp.find(more) != mp.end())
        {
            cout << mp[more] << " " << i;
            return;
        }
        else
        {
            mp[arr[i]] = i;
        }
    }
    cout << -1; //agar pair nahi mila toh -1 print karna hoga.
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