//Printing subsequences with sum equal to k.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"

vector<int> arr;
int k;
int sum = 0;
void psub(int i, vector<int> &carr, int sum)
{
    if (i == arr.size())
    {
        if (sum == k)
        {
            for (int i = 0; i < carr.size(); i++) {cout << carr[i] << " ";}
            cout << endl;
        }
        return;
    } 

    //take
    carr.pb(arr[i]);
    sum += arr[i];
    psub(i+1, carr, sum);

    //not take
    carr.pop_back();
    sum -= arr[i];
    psub(i+1, carr, sum);

}
void VivekTiwary_1092()
{
    int n; cin >> n;
    arr.resize(n);
    for (auto &x : arr) {cin >> x;}
    cin >> k;
    vector<int> carr;
    psub(0, carr, 0);
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