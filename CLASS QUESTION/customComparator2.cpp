//The custom_sort structure defines a custom comparator for sorting pair<int, int>. 
//This comparator is used in STL containers like set, multiset, and priority_queue.

//also see customComparator1.cpp

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

// Custom comparator structure
struct custom_sort 
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        if (a.first == b.first) 
        {
            return a.second > b.second; // Sort by second in descending order if first values are equal.
        }
        return a.first < b.first; // Otherwise, sort by first in ascending order.
    }
};

void VivekTiwary_1092()
{
    // Example data
    vector<pair<int, int>> data = 
    {
        {3, 2}, {1, 4}, {3, 5}, {1, 2}, {2, 3}
    };

    // Using custom_sort with std::set
    set<pair<int, int>, custom_sort> st;//syntax to call incase of set.
    for (const auto &p : data) 
    {
        st.insert(p);
    }
    cout << "Set contents (sorted):\n";
    for (const auto &p : st) 
    {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }

    // Using custom_sort with std::multiset
    multiset<pair<int, int>, custom_sort> ms;//syntax to call incase of multiset.
    for (const auto &p : data) 
    {
        ms.insert(p);
    }
    cout << "\nMultiset contents (sorted, duplicates allowed):\n";
    for (const auto &p : ms) 
    {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }

    // Using custom_sort with priority_queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, custom_sort> pq;
    //Line 60 gives syntax to call incase of priority queue.
    for (const auto &p : data) 
    {
        pq.push(p);
    }
    cout << "\nPriority Queue contents (based on custom order):\n";
    while (!pq.empty()) 
    {
        auto p = pq.top();
        pq.pop();
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