#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

// Custom comparator function for sorting pairs.
bool custom_sort(const pair<int, int> &a, const pair<int, int> &b) 
{
    if (a.first == b.first) 
    {
        return a.second > b.second; // If first elements are equal, sort by second in descending order.
    }
    return a.first < b.first; // Otherwise, sort by first in ascending order.
}

// Generalconfusion:
// Which sign is to be used for ascending or descending?
// <means ascending
// >means descending


void VivekTiwary_1092()
{
    int n;
    cout << "Enter the number of pairs: ";
    cin >> n;

    vector<pair<int, int>> vec;

    // Input the pairs.
    cout << "Enter " << n << " pairs (format: first second):\n";
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vec.push_back({x, y});
    }

    // Sort the vector of pairs using the custom comparator.
    sort(vec.begin(), vec.end(), custom_sort);//syntax to call comparator sort.

    // Print the sorted pairs.
    cout << "Sorted pairs:\n";
    for (const auto &p : vec) {
        cout << "(" << p.first << ", " << p.second << ")\n";
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