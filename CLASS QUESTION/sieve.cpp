#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    bool prime[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        prime[i] = 1;
    }
    prime[0] = 0;
    prime[1] = 0;

    for (int i = 2; i <= sqrt(n); i++) // i*i <= n lena chaihiya kyuki sqrt jada time leta hai
    {
        if (prime[i] == 1)
        {
            for (int j = i * i; j <= n + 1; j = j + i)
            {
                prime[j] = 0;
            }
        }
    }

    for (int i = 2; i < n + 1; i++)
    {
        if (prime[i] == 1)
        {
            cout << i << ' ';
        }    
    }
    return 0;
}
