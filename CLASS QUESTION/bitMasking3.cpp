// Q)Given any set of n elements, iterate through all the subsets (submasks) of all the
// subsets (submasks) of size n, basically sare subsets print karne hai for the number n.
// Given set can be written as 111111...1 (1’s n times)
// aur uska 2^n subsets hi hoga.
//agar n == 3 hai toh 2^3 = 8 toh 0 to 7 har number ke liye uska subsets ke corresponding wala
//number generate karega.
//Time Complexity :- 3^n as TC = summation(1 to n)[(nck)2^k] = 3^n, as wo sare n mein se koi k ko set bit mane aur phir inner loop 
//2^k times chalega.
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

void VivekTiwary_1092()
{
    int n; 
    cin >> n;
    for (int i = 0; i < (1 << n); i++)
    {
        for (int x = i; x > 0; x = (x - 1) & i) //line 19 to 23 is same as we did in bitMasking2.cpp
        {//but there we did for a particular number we found all the subsets, but here we are 
            cout << x << '\n'; //finding subsets for each subset of the number n.
        }
        cout << 0 << '\n'; // treat 0 separately
    }
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