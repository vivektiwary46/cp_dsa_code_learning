
// prefix[i] = sum of all the elements till index i.
// prefix array calculate karne ka profit ye hai ki agar q query dia hua hai aur ham phele se
// prefix array calculate karke rakhe hai toh O(q) mein hi kam ho jayega, kyuki uske andar agar
// l se r tak sum nikalana hai toh sidhe sum = prefix[r] - prefix[l-1] kar sake hai jo O(1) mein
// ho jayega isse, time complexity ghat jata hai.
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int arr[N];  // koi bhi global array ka sara element zero hota hai.
int prefix[N];
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

    int prefix[n];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << prefix[i] << " ";
    }

    return 0;
}