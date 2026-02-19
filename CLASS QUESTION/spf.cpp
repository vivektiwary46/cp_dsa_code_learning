#include <bits/stdc++.h>
using namespace std;
int spf[1000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i <= 1e6; i++)
    {
        spf[i] = i;
    }
    for (int i = 2; i <= sqrt(1e6); i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= 1e6; j = j + i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        cout << "The smallest prime factor of " << x << " is " << spf[x]<<endl;
    }
    return 0;
}