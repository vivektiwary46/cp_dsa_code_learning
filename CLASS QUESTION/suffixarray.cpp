// lets say int arr[n]
// suffix array = suffix[i] = array ka n-1 index pe jo value hai se i index pe jo value hai unsab ka sum dega suffix[i];


#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int suffix[n];
    suffix[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] + arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << suffix[i] << " ";
    }
    return 0;
}