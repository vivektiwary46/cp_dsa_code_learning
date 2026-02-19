//Here we are counting the number of subsequences with sum k, but here we will find it
//recursively and not using global variables.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"

//TC = O(2^N)
vector<int> arr;
int n, k;

int psub(int i, int sum)
{
    if (sum > k) {return 0;} //this base case reduces TC more, but without this
    //also the code works.
    if (i == n)
    {
        if (sum == k) {return 1;}
        else return 0;
    }
    
    //PICK
    sum += arr[i];
    int l = psub(i+1, sum);

    //NOT PICK
    sum -= arr[i];
    int r = psub(i+1, sum);

    return l + r;
}
void VivekTiwary_1092()
{
    cin >> n; arr.resize(n);
    for (int i = 0; i < n; i++) {cin >> arr[i];}
    cin >> k;
    cout << psub(0, 0);
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