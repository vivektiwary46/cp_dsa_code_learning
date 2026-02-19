//Given an array arr of n integers and an integer x. Array arr is sorted in 
//non-decreasing i.e arr[i] <= arr[i+1]. Write C++ program to find any position 
//i such that arr[i] = x. If x is not present in the array, i = -1. Print i.

#include<bits/stdc++.h>
using namespace std;
#define int long long
//Note :- array already non-decreasing dia hau hai so hame sort karne ka jarurat nahi hai
//is not given then we needed to sort the array.
void VivekTiwary_1092()
{
    int n;
    cin >> n;
    int arr[n];
    for (auto &x : arr)
    {
        cin >> x;  // took input of the array
    }
    int target;
    cin >> target; // took input of the target element we want to find in the array.
    int low = 0;   // rest is the logic, see notes 14 of codeism.
    int high = n-1;
    int pos = -1;
    while (low <= high)
    {
        int mid = low + ( high - low ) / 2; // we are not using mid = (low + high) / 2 as this formula
                                            // may overflow, hence the mid = low+(high - low)/2 is used , it helps to avoid overflow.
        if (arr[mid] == target)
        {
            pos = mid ;
            break;
        }

        else if (arr[mid] < target)
        {
            low = mid + 1; //low = mid + 1 and high = mid - 1 , karne se there is one gaurantee that there will be a 
                           //point when low will become greater than high and at that time we will break the loop.
        }
        else 
        {
            high = mid - 1;
        }
    }
    cout << pos << '\n';
    // Time complexity :- O(logN , base of log is 2) [as at every step we are reducing the active region by half]
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    VivekTiwary_1092();
    return 0;
}