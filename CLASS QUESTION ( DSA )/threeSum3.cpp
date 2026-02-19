// this time we are using two pointer approach to do this.
// TC :- O(nlogn) + O(n^2), in this also it is been done in O(n^2), only.
// that O(nlogn) is because we are using sort function.
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define pb push_back

void VivekTiwary_1092()
{
    int n;
    cin >> n;
    int arr[n];
    for (auto &x : arr)
    {
        cin >> x;
    }
    sort(arr, arr + n);
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp;
                temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && arr[j] == arr[j-1]) {j++;}
                while (j < k && arr[k] == arr[k-1]) {k--;}
            }
        }
    }
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