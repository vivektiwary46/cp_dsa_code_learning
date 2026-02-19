//Written the code to find whether a given string is a palindrome or not.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"

//code is written using recursion and have just used a single variable i to traverse 
//through the string.
//TC :- O(N/2)
//SC :- O(N/2)
string s;
bool f(int i)
{
    int n = s.size();
    if (i >= n/2) {return true;}
    if (s[i] != s[n-1-i]) {return false;}   
    return f(i+1);
}
void VivekTiwary_1092()
{
    cin >> s;
    if (f(0)) {cout << "YES" << endl;}
    else {cout << "NO" << endl;}
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