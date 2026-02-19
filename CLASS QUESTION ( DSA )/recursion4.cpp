//we want to print sum from 1 to n using recursion.
//here we have written the code using paramaterized recursion.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"

void f(int i, int sum)
{
    if (i < 1)
    {
        cout << sum << endl; return;
    }
    f(i-1, sum+i);
}
void VivekTiwary_1092()
{
    int n; cin >> n;
    f(n, 0);
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