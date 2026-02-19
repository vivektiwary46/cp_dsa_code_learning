//Now the problem is same as dp6.cpp but there is a slight variation
//Question :-
//Suppose you are given n objects where the ith object has weight Wi and a profit or value
//Vi. Also you have a knapsack which has a maximum weight capacity of X, you have to tell 
//the maximum value or profit you can achieve by picking a subset of objects such that the
//total weight of objects in the knapsack does not exceed the maximum capacity.
//Let the constraints be : N <= 1𝑒2 , 𝑊𝑖 <= 1𝑒5 , 𝑋 <= 1𝑒5, 𝑉𝑖 <= 1𝑒5

//yaha pe bhi bol sakte hai ki dp ka state, n ke sath, w,x,v mein se koi ek hoga, so 
//constraints dekh ke state ka pata lagaya jaa sakta hai...

//State :  dp[𝑖][𝑗] = 𝑚𝑎𝑥 𝑝𝑟𝑜𝑓𝑖𝑡 𝑝𝑜𝑠𝑠𝑖𝑏𝑙𝑒 𝑏𝑦 𝑠𝑒𝑙𝑒𝑐𝑡𝑖𝑛𝑔 𝑎 𝑠𝑢𝑏𝑠𝑒𝑡 𝑓𝑟𝑜𝑚 𝑡ℎ𝑒 𝑓𝑖𝑟𝑠𝑡 𝑖 𝑜𝑏𝑗𝑒𝑐𝑡𝑠 ℎ𝑎𝑣𝑖𝑛𝑔 𝑎 
//𝑡𝑜𝑡𝑎𝑙 𝑤𝑒𝑖𝑔ℎ𝑡 𝑜𝑓 𝑗. 
// Transition :     not taken,          taken
//  dp [i][j] = max(dp[i − 1][j], dp[i − 1][j − 𝑤[i]] + v[i])  ---- A
//according to A, agar i-1 tak j weight ban gaya hai, toh i pe v[i] nahi lie aur i-1 tak
//kuch value ban chuka hoga, but if i-1 tak j-w[i] weight bana hai aur hamlog w[i] leke
//j weight banana chah rahe hai, toh abhi tak jo value bana tha usme v[i] bhi add hoga,
//aur un dono ka max hi, dp[i][j] mein store hoga....
//isko aur achse se table se samjhaye hai, in class 12 - 0-1 kanpsack pdf print out....

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

//Time complexity : O(𝑛 * 𝑥)
//Space complexity : O(𝑛 * 𝑥)  

int dp[(int)1e2 + 1][(int)1e5 + 1]; 
//once the table in PDF 36 is understood the code will be more clear, table is made on
//page 1, handwritten....
void VivekTiwary_1092()
{
    int num_obj, max_capacity; cin >> num_obj >> max_capacity; 
    vector<int> w(num_obj), v(num_obj); 
    for (int i = 0; i < num_obj; i++) {cin >> w[i] >> v[i];} 
 
    fill_n(&dp[0][0], ((int)1e2 + 1) * ((int)1e5 + 1), -1e18); //doubt....

    dp[0][0] = 0;  //base case.
    for (int i = 1; i <= num_obj; i++) { 
        for (int j = 0; j <= max_capacity; j++) 
        { 
            dp[i][j] = dp[i - 1][j]; //not taken 
            if (j - w[i - 1] >= 0) 
            {dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);} //taken 
        } 
    } 
    int mx = -1e18; 
    for (int i = 0; i <= max_capacity; i++) {mx = max(mx, dp[num_obj][i]);} 
    cout << "Max profit possible = " << mx; 
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