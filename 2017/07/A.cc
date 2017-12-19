#include "../../includes/util.hpp"

map<string, vs> adj;
map<string, int> weights;

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
    for (auto it : adj) {
        if (!ischild.count(it.first)) root = it.first;
    }
    cout << root << endl;
}

