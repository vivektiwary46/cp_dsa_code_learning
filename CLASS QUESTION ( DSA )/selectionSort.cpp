//Goal is to sort the array, but technique used will be different
//What we do is select minimums and swap, for every index we see if there is some other element
//from i+1 to n-1 index which is just smaller to it, and swap it, we need to do this for just till 
//n-2 index and job will be done.
#include <bits/stdc++.h>
using namespace std;
#define int long long

//Time Complexity = O(n^2);
void VivekTiwary_1092()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    for (int i = 0; i <= n-2; i++)
    {
        int mini = i;
        for (int j = i+1; j <= n-1; j++)
        {
            if (a[j] < a[mini]) { mini = j; }
        }
        swap(a[i], a[mini]);
    }
    for (auto &x : a) {cout << x << " ";}
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