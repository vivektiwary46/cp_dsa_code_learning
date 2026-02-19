//This algorithm is based on recursion.
//Youtube Link :- https://www.youtube.com/watch?v=ogjf7ORKfd8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=8
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"

int n;
vector<int> arr;

//TC :- O(N*log2(N)) -> merge take at max N time and total merge sort log2N mein complete
//ho jata hai.
//SC :- O(N) -> wo just temp bana rahe hai, jo at max N space lega.

void merge(int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right]) 
        {
            temp.pb(arr[left]); 
            left++;
        }
        else 
        {
            temp.pb(arr[right]); 
            right++;
        }
    }

    while (left <= mid) 
    {
        temp.pb(arr[left]); 
        left++;
    }

    while (right <= high) 
    {
        temp.pb(arr[right]); 
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low]; //yaha in temp we are writing i - low as, i starts from 
        //low but temp mein indexing stats from 0 -> recursion tree se pata chal jayega.
    }
}

void mergeSort(int low, int high)
{
    //base case
    if (low == high) {return;}
    int mid = (low + high) / 2;
    mergeSort(low, mid);
    mergeSort(mid + 1, high);
    merge(low, mid, high);
}
void VivekTiwary_1092()
{
    cin >> n; arr.resize(n);
    for (int i = 0; i < n; i++) {cin >> arr[i];}
    mergeSort(0, n-1);
    for (int i = 0; i < n; i++) {cout << arr[i] << " ";}
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