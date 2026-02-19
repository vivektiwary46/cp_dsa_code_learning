//Optimisation 2 : (one array) for dp8kanpsack.cpp
//Read the page 3, page 4, page 5 of PDF 36, handwritten one where it is discussed how 
//optimisation 2,can be performed, once read the code will be more clear....

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

//TC : O(n*x);
//SC : O(x); space complexity optimized from 2*x to x, it is optimized by only a 
//coefficient of only 1 but still at production level it is of very importance......


void VivekTiwary_1092()
{
    int num_objects, max_capacity;
    cin >> num_objects >> max_capacity;
    vector<int> w(num_objects), v(num_objects);
    for (int i = 0; i < num_objects; i++)
    {
        cin >> w[i] >> v[i];
    }
    //code :
    vector<int> dp(max_capacity + 1, -1e18); 
    dp[0] = 0; 
    for (int i = 1; i <= num_objects; i++) 
    { 
        for (int j = max_capacity; j >= w[i - 1]; j--) 
        {//note that the loop must go in reverse or we risk overcounting 
            dp[j] = max(dp[j], dp[j - w[i - 1]] + v[i - 1]); // take current object 
        } 
    } 
    cout << "Max profit possible " << *max_element(dp.begin(), dp.end()); 
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        VivekTiwary_1092();
    }
    return 0;
}
