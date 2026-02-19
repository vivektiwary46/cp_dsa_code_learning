#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;

const ull M = 1e9 + 7;
int n;
vector<vector<pair<int, ull>>> adj;
vector<ull> d;

void dfs(int u, int p) {
    for (auto temp : adj[u]) {
        int v = temp.first;
        ull w = temp.second;
        if (v == p) continue;
        d[v] = d[u] ^ w;
        dfs(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    adj.assign(n + 1, {});
    for (int i = 0; i < n - 1; i++) {
        int u, v; ull w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    d.assign(n + 1, 0);
    dfs(1, 0);

    ull ans = 0;
    for (int i = 0; i <= 61; i++) {
        ull on = 0, off = 0;
        for (int j = 1; j <= n; j++) {
            if (d[j] & (1ull << i)) on++;
            else off++;
        }
        ans = (ans + ((1ull << i) % M) * off * on) % M;
    }

    cout << ans << "\n";
}
