#include<bits/stdc++.h>
using namespace std;

//memoization code : TC = O(N^2) , SC = O(N^2) + ASC i.e. O(N);
int f(int ind, int prevInd, int n, vector<int> &nums, vector<vector<int>> &dp)
{
    if (ind == n) {return 0;}
    if (dp[ind][prevInd + 1] != -1) return dp[ind][prevInd + 1];

    //notake
    int notake = f(ind + 1, prevInd, n, nums, dp);

    //take
    int take = 0;
    if (prevInd == -1 || nums[ind] > nums[prevInd]) {take = 1 + f(ind + 1, ind, n, nums, dp);}
    return dp[ind][prevInd + 1] = max(take, notake);
}

int main()
{
    cout << "Enter the size of the nums array : "; 
    int n; cin >> n;
    cout << "Enter the nums array : ";
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {cin >> nums[i];}
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    cout << "LIS is : " << f(0, -1, n, nums, dp);
}