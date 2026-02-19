#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"

//In this we want to start form i index and 0 to i wale array ke part mein i ko uske 
//correct postion pe le jana hai, so i se 0 tak compare karte rahe hai to put it in its
//correct position and do it with all the i to get the final sorted array, now if array 
//is already sorted whenever we take a i, it will be in it's correct position so we
//arr[j-1] > arr[j] wala condition immediately fail kar jayega (j was intialized to i everytime)
//hence time complexity = O(n^2) and best case is O(n).
void VivekTiwary_1092()
{
    int n;
    cin >> n;
    int arr[n];
    for (auto &x : arr) { cin >> x; }
    for (int i = 0; i <= n-1; i++)
    {
        int j = i;
        while(j > 0 && arr[j-1] > arr[j]) //as soon as arr[j-1] > arr[j] becomes false it
        //it means that the ith element which was intialized to j is at it's correct 
        //position now.
        {
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
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