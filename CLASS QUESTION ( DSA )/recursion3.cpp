//this is also a program of backtracking, yaha N to 1 print kar rahe hai but i+1 use kie hai,
//same, print(i + 1, n); ye statement phele likh die hai, cout << i << endl; aur ye statement bad mein.
#include <bits/stdc++.h>
using namespace std;
#define int long long

void print(int i, int n)
{
    if (i > n)
    {
        return;
    }
    print(i + 1, n);
    cout << i << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    print(1, n);

    return 0;
}