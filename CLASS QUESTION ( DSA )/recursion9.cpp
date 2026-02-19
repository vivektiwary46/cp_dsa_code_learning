//here we are printing subsquences 
//Youtube Link :- https://www.youtube.com/watch?v=AxNNVECce8c&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=6
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"

//TC = O(2^N * N) -> as har element ko either pick or not pick kar sakte hai toh 2 options
//so 2^N and for priting it, max N ho sakta hai.

//SC = O(N) as stack space mein maximum N functions hi wait kar raha hoga, so O(N), 
//recursion tree banake dekh sakte hai.

vector<int> arr;
void psub(int i, vector<int> &arr, vector<int> &carr)  //arr -> original array, carr -> 
{//current array jo abhi print hoga.
    if (i == arr.size()) 
    {
        for (int i = 0; i < carr.size(); i++)
        {
            cout << carr[i] << " ";
        }
        cout << "\n";
        return;
    }

    //take the current element
    carr.pb(arr[i]);
    psub(i+1, arr, carr);

    //not take the current element
    carr.pop_back();
    psub(i+1, arr, carr);

    //important observation :- let us say arr = {3, 1, 2}, so psub(0, arr, []) se
    //if take kie toh psub(1, arr, [3]) banega aur not take kie toh psub(1, arr,[]) banega, now 
    //note according to code ye bactracking ke waqt hi jab pub(1, arr, [3]) se jab pop kie 
    //honge last element tab hi psub(1, arr, []) bana hoga, aise hi sara cases ban jayega
    //take and not take se, actually sara cases cater ho jayega, recursion tree banake 
    //dekh sakte hai.

    //NOTE -> Recursion tree aur code same hi hota hai.
}

void VivekTiwary_1092()
{
    int n; cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {cin >> arr[i];}
    vector<int> carr;
    psub(0, arr, carr);
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