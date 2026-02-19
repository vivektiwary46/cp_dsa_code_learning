#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int prime[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        prime[i] = 1;
    }
    prime[0] = 0;
    prime[1] = 1;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (prime[i] == 1)
        {
            for (int j = i * i; j <= n; j = j + i)
            {
                prime[j] = 0;
            }
        }
    }
    int sum = 0;
    for (int i = 2; i < n + 1; i++)
    {
        if (prime[i] == 1 && n % i == 0)
        {
            sum = sum + i;
        }
    }

    cout << sum;
    return 0;
}