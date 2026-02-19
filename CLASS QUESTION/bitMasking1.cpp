//We are given a set in the form of an array and we need to generate all the subsets of that set.
//so if the set is A = [2,4,5]; so the bitmask which will represent the set is 110100, but
//for the representing subsets of it we need the numbers from 0 to 2^n-1 where n is the 
//size of the set A and from 0 to 2^n-1 is 2^n and we know that total 2^n subsets are present 
//for any set, the bits present in the number will represent the set , as
//0 -> 000 -> []      4 -> 100 -> [5]
//1 -> 001 -> [2]     5 -> 101 -> [2,5]
//2 -> 010 -> [4]     6 -> 110 -> [4,5]
//3 -> 011 -> [2,4]   7 -> 111 -> [2,4,5]
//see as 7 is 111 in binary so all the bits at 0,1,2 index is set so all the elements of set
//A at 0,1,2 index will be present in the subset.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
//TC = O(n*2^n);
vector<vector<int>> subsets(vector<int>& nums)
{
    int n = nums.size();
    int subset_cnt = (1<<n);
    vector<vector<int>> subsets;
    for (int mask = 0; mask < subset_cnt; mask++)
    {
        vector<int> subset;
        for (int i = 0; i < n; i++) //jitna set wala array ka size hoga (2^n) - 1 wala number mein bhi n hi max bits hoga toh sare ke liye max n bits check karna sufficient hoga.
        {
            if (mask & (1<<i)) {subset.push_back(nums[i]);}
        }
        subsets.push_back(subset);
    }
    return subsets;
}
void VivekTiwary_1092()
{
    int n; cin >> n; 
    vector<int> v(n);
    for (int i = 0; i < n; i++) {cin >> v[i];}
    vector<vector<int>> all_subsets = subsets(v);
    int x = all_subsets.size();
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < all_subsets[i].size(); j++)
        {
            cout << all_subsets[i][j] << " ";
        }
        cout << "\n";
    }
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