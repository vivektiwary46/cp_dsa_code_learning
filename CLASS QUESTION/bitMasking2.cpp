//Q)Given any number n, iterate through all the submasks(subsets) of n. (in decreasing order) 
//Eg :- if n=1010 all its submask will be -> 1010(10), 1000(8), 0010(2), 0000(0).
//for this we need to perform a simple operation as done in the for loop, remember it
//1)Subtract 1 from each sub mask,
//2)And then take bitwise and (&) with the original mask
//Time Complexity :- 2^number of set bits, as wo set bit ko 0 karenge ya 1 rehne denge while getting the subsets.
//if n == 7, all the numbers from 0 to 7 will come as 7 is itself 111.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

void VivekTiwary_1092()
{
    int n; cin >> n;
    for (int x = n; x > 0; x = (x-1)&n)
    {
        cout << x <<"\n";
    }
    cout << 0 << "\n";  // treat 0 separately
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