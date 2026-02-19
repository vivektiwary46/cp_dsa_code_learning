//here also we are going to write the code to print sum of 1 to n numbers 
//but here we will use the functional recursion appraoch.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"

//in the similar manner we could have written code for factorial of n numbers.
int f(int n)
{
    if (n == 0) {return 0;}
    return n + f(n-1);
}
void VivekTiwary_1092()
{
    int n; cin >> n;
    cout << f(n) << endl;
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