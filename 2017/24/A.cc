#include "../../includes/util.hpp"

int n;
vector<pii> arr;
map<int, vi> adj;
vi vis, sum;

int rev(int i, int x) {
    if (arr[i].X == x) return arr[i].Y;
    return arr[i].X;
}

int dfs(int w) {
    int res = 0;
    for (int v : adj[w]) {
        if (vis[v]) continue;
        vis[v] = 1;
        res = max(res, sum[v] + dfs(rev(v, w)));
        vis[v] = 0;
    }
    return res;
}

int main() {
    int u, v;
    char c;
    
    while (cin >> u) {
        cin >> c >> v;
        n++;
        arr.emplace_back(u, v);
        sum.emplace_back(u + v);
    }

    for (int i = 0; i < n; i++) {
        pii p = arr[i];
        adj[p.X].push_back(i);
        adj[p.Y].push_back(i);
    }

    vis.assign(n, 0);
    int res = dfs(0);
    cout << res << endl;
}
