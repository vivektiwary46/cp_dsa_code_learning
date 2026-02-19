#include <bits/stdc++.h>
using namespace std;

int f(int mask, int pos, int vis_all, vector<vector<int>> &dis, vector<vector<int>> &dp)
{
    if (mask == vis_all) {return dis[pos][1];} // return cost to come back to city 1
    if (dp[mask][pos] != -1) {return dp[mask][pos];}

    int ans = 1e9;
    int n = dis.size() - 1; // since 1-indexed

    for (int city = 1; city <= n; city++)
    {
        if ((mask & (1 << city)) == 0) // if city not visited
        {
            int newans = dis[pos][city] + f(mask | (1 << city), city, vis_all, dis, dp);
            ans = min(ans, newans);
        }
    }
    return dp[mask][pos] = ans;
}

int main()
{
    cout << "Enter the number of vertices : ";
    int v; cin >> v;

    vector<vector<int>> dis(v + 1, vector<int>(v + 1));
    cout << "Enter the adjacency matrix (1-indexed): " << endl;
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            cin >> dis[i][j];
        }
    }
    int vis_all = (1 << (v + 1)) - 2; // all cities 1..v visited (skip 0th bit)
    vector<vector<int>> dp(vis_all, vector<int>(v + 1, -1));
    int ans = f(1 << 1, 1, vis_all, dis, dp);
    cout << "The minimum Hamiltonian cycle cost is: " << ans << endl;
    return 0;
}
