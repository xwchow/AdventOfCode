#include "../../includes/util.hpp"

map<string, vs> adj;
map<string, int> weights;


int majority(const vi& v) {
    map<int, int> cnt;
    for (int x : v) cnt[x]++;
    for (auto &it : cnt)
        if (it.second > 1)
            return it.first;
}

int num_unique(const vi& v) {
    return set<int>(v.begin(), v.end()).size();
}

int dfs(const string& u) {
    vi ws;
    for (string& v : adj[u]) {
        ws.push_back(dfs(v));
    }
    int uniq = num_unique(ws);
    if (uniq <= 1) return accumulate(ws.begin(), ws.end(), 0) + weights[u];

    int maj = majority(ws);
    int n = adj[u].size();
    for (int i = 0; i < n; i++) {
        if (ws[i] != maj) {
            int diff = maj - ws[i];
            int res = weights[adj[u][i]] + diff;
            cout << res << endl;
            exit(0);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(0);
    string line;

    map<string, bool> ischild;
    while (getline(cin, line)) {
        vs words = split(line);
        string par = words[0];
        int w = stoi(words[1].substr(1));
        weights[par] = w;
        for (int i = 3; i < (int)words.size(); i++) {
            string child = words[i];
            if (child.back() == ',') child.pop_back();
            adj[par].push_back(child);
            ischild[child] = true;
        }
    }
    string root;
    for (auto &it : adj) {
        if (!ischild.count(it.first)) root = it.first;
    }
    dfs(root);
}

