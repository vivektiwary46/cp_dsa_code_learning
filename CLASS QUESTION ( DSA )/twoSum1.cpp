// We are given an array and and a target value and we need to find whether whether we can use
// the two elements of the array and sum it up to get the target value, if we don't get such pair cout -1.
// here we are writing the brute force approach for this.
// Time complexity = O(N^2).
// Link for the theory :- https://www.youtube.com/watch?v=UXDSeD9mN-k&list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&index=21
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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            else if (arr[i] + arr[j] == target)
            {
                cout << i << " " << j;
                return;
            }
        }
    }
    cout << -1;
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