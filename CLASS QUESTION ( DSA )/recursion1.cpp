//Recursively printing name from i to n. 
#include <bits/stdc++.h>
using namespace std;
#define int long long

void print(int i, int n)
{
    if (i > n)
    {
        return;
    }    
    else
    {
        cout << "VIVEK" << endl;
    }
    print(i + 1, n);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i, n;
    cin >> i >> n;
    print(i, n);
    return 0;
}