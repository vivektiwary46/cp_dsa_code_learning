//Optimisation 1 : (two arrays) for dp8kanpsack.cpp
//Read the page 2 of PDF 36, handwritten one where it is discussed how optimisation 1,
//can be performed, once read the code will be more clear....

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

//TC : O(n*x);
//SC : O(2*x); space complexity optimized.....

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
    vector<int> prev(max_capacity + 1, -1e18), curr(max_capacity + 1, -1e18); 
    prev[0] = 0; 
    for (int i = 1; i <= num_objects; i++) 
    { 
        curr = prev;
        for (int j = w[i - 1]; j <= max_capacity; j++) 
        { 
            curr[j] = max(prev[j], prev[j - w[i - 1]] + v[i - 1]); 
        } 
        prev = curr; 
    } 
    cout << "Max profit possible " << *max_element(curr.begin(), curr.end());
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