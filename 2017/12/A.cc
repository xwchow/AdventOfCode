#include "../../util.hpp"

const int N = 2000;

vi adj[N];
int vis[N];

int dfs(int u) {
    vis[u] = 1;
    int sz = 1;
    for (int v : adj[u]) {
        if (!vis[v]) {
            sz += dfs(v);
        }
    }
    return sz;
}

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(0);

    string line;
    while (getline(cin, line)) {
        vs words = split(line);
        int u = stoi(words[0]);
        for (int i = 2; i < words.size(); i++) {
            string w = words[i];
            if (w.back() == ',') w.pop_back();
            int v = stoi(w);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    cout << dfs(0) << endl;
}

