#include<bits/stdc++.h>
using namespace std;
#define int long long
//Time Complexity = O(n^2) -> worst time complexity , as if array is sorted my loop will only run for one time
//and in that case time complexity will be O(n), hence used the didswap variable;
//in this we do adjacent swaps i.e. intially i ko n-1 pe set kie and j ko 0 se i-1 tak le
//gaye and kept swapping arr[j] and arr[j+1], by this greatest element would come at last
//now again kept i at n-2 as n-1 pe already array ka highest element aa gaya hoga, again 
//did the process by setting i at n-2 and j from 0 to i-1, so 2nd highest element would
//now come at second last place and in this way we would sort the full array. so agar array
//sorted hoga so first iteration mein hi koi swap nahi hoga and didswap would be zero so
//break kar die, so best case time complexity becomes O(n).
void VivekTiwary_1092()
{
    int n;
    cin >> n;
    int arr[n];
    for (auto &x : arr) { cin >> x; }
    for (int i = n-1; i >= 1; i--)
    {
        int didSwap = 0;
        for (int j = 0; j <= i-1; j++)
        {
            if (arr[j] > arr[j+1] && j+1 < n)
            {
                swap(arr[j], arr[j+1]);
                didSwap = 1;
            }
        }
        if (didSwap == 0)
        {
            break;
        }
    }
    for (auto &x : arr)
    {
        cout << x << " ";
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