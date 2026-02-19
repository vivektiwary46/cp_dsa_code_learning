// In this we will see important precomputation techniques which will be used in many intermediates steps in many questions
// We will learn by solving this question :- https://www.hackerrank.com/challenges/crush/problem
// Link to see online :- https://www.youtube.com/watch?v=4wqDE1zNUwc&list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&index=22
// Also can see copy , point 22.
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7 + 1;
int arr[N];
int n;

void VivekTiwary_1092()
{
    
    int a, b, k;
    cin >> a >> b >> k;
    arr[a] += k;
    if ((b+1) < N)  //ensure that b+1 is not out of bound
    {
        arr[b + 1] -= k; //O(1)
    }
    
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        VivekTiwary_1092(); //O(m)
    }
    vector<int> pf(n+1, 0);  //intialized all the values to zero so that there is no segmentation fault.
    pf[1] = arr[1];
    for (int i = 2; i <= n; i++)
    {
        pf[i] = pf[i - 1] + arr[i]; //O(n)
    }

    int mx = -1;
    for (int i = 1; i <= n; ++i)
    {
        if (pf[i] > mx)
        {
            mx = pf[i];    //O(n)
        }
    }
    cout << mx << '\n';
    //Total time complexity :- O(n) + O(n) + O(m) - whcih is less than if we would have used brute force.
    return 0;
}