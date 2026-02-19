//Printing subsequences with sum K, but as soon as we get the first such subsequence
//we stop the program -> we are using technique to print just one subsequences.
//This could also be done with the help of a global variable but we are refraining from
//it and learning how to do it recursively.
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
bool psub(int i, vector<int> &carr, int sum)
{
    if (i == arr.size())
    {
        if (sum == k)
        {
            for (int i = 0; i < carr.size(); i++) {cout << carr[i] << " ";}
            cout << endl;
            return true;
        }
        return false;
    } 

    //take
    carr.pb(arr[i]);
    sum += arr[i];
    if (psub(i+1, carr, sum) == true) {return true;}

    //not take
    carr.pop_back();
    sum -= arr[i];
    if (psub(i+1, carr, sum) == true) {return true;}

    return false;
}
void VivekTiwary_1092()
{
    int n; cin >> n;
    arr.resize(n);
    for (auto &x : arr) {cin >> x;}
    cin >> k;
    vector<int> carr;
    psub(0, carr, 0);
    if (psub(0, carr, 0) == false) {cout << "NO SUCH SUBSEQUENCE";}
   
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