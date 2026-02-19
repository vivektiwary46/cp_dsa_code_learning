//Given an array arr of n integers consiting of 0's and 1's and all the 1's are 
//after all the 0's, find the position of the first 1. 
//in this question as the arry look monotonic we can use binary search,
//whenever the array looks monotonic and we need to find some particular element in the 
//array we can use bianry search.

#include<bits/stdc++.h>
using namespace std;
#define int long long

void VivekTiwary_1092()
{
    int  n;
    cin >> n;
    int arr[n];
    for (auto &x : arr)
    {
        cin >> x;
    }
    int low = 0;
    int high = n-1;
    int pos = -1;
    while (high >= low) //dry run for this example = 0 0 0 0 0 1 1 1 1, the code will get clear.
    {
        int mid = low + (high - low)/2;
        if (arr[mid] == 0)
        {
            low = mid + 1; //low = mid + 1 and high = mid - 1 , karne se there is one gaurantee that there will be a 
                           //point when low will become greater than high and at that time we will break the loop.
        }
        else 
        {
            pos = mid;
            high = mid - 1;
        }
    }
    cout << pos << '\n';

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    VivekTiwary_1092();
    return 0;
}