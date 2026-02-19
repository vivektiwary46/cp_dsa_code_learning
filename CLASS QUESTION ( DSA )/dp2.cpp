//Read the code in dp2.cpp of class question, here we are just optimizing the space for it.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"
//The most optimized way to print fibonnacci numbers.
//TC :- O(N)
//SC :- O(1)
//can also watch video 1 of dp playlist from 27:45 mins.
void VivekTiwary_1092()
{
    int n; 
    cin >> n;
    int prev2 = 0; 
    int prev1 = 1;
    for (int i = 2; i < n+1; i++)
    {
        int curri = prev1 + prev2;  //kisi i pe jake dekhna aisa kyu likha hai.
        prev2 = prev1;
        prev1 = curri;
    }
    cout << prev1;
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