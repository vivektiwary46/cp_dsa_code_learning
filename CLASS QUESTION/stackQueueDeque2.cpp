// Question Link :- https://www.codechef.com/problems/DC206
// This is a standard question which can be asked in the interviews.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
// Logic :- n-1 se chal rahe hai aur har element ke liye uske aage ke saare bade element
// ko pop kar de rahe hai aur agar ye sab karne ke bad stack empty nahi hai toh top wala
// element is the answer otherwise -1 is the answer.

//as stack mein n-1 se elements ko push kar rahe hai so, jab upar wala condition jo ham likhe
//hai wo check karna suru karenge ith element ke liye toh uske right wale element pe hi check
//hoga aur yahi hame karna bhi hai, we want next greater element from its right.

// TC is O(n) and not O(n^2) as for loop toh n bar chalega but while loop in total n-1 bar 
// hi chalega as each element can be popped from the stack for only one time in worst case
// as ho sakta hai sare ko pop karne ka jarurat bhi na pade but 0th index wala push karne
// bad uske pop karna hi nahi hoga, so in worst case loop n-1 bar chalega, so in terms of 
//operations overall 2n-1 operation hi hoga.
void VivekTiwary_1092()
{
    int n; cin >> n;
    int a[n];
    for (auto &x : a) {cin >> x;}
    int ans[n];
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && a[i] >= s.top()) { s.pop(); }
        if (!s.empty()) {ans[i] = s.top();}
        else {ans[i] = -1;}
        s.push(a[i]);
    }
    for (auto &x : ans) {cout << x << " ";}
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