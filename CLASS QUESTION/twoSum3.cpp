//We need to do the same as in twoSum1.cpp but in a better time complexity, but here we are just
//printing yes if we found the target and no if not, if we want to print the indexes, appraoch used 
//in twoSum2.cpp is best as here we will sort the array, so to print the indexes we have to store 
//the indexes in some other data structure like map.
//Time Complexity will be O(N).
//Space Complexity will also be O(N) as we are sorting the array.
//here we are using two pointer appraoch.
#include<bits/stdc++.h>
using namespace std;
#define int long long

void VivekTiwary_1092()
{
    int n;
    cin >> n;
    int arr[n];
    for (auto &x : arr) { cin >> x; }
    int l = 0;
    int r = n-1;
    sort(arr, arr+n);
    int target;
    cin >> target;
    while (l < r)
    {
        int sum = arr[l] + arr[r];
        if (sum == target) {cout << "YES"; return;}
        else if (sum < target) {l++;}
        else {r--;}
    }
    cout << "NO";
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
