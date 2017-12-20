#include "../../includes/util.hpp"

#define int ll

int man(vi &v) {
    return abs(v[0]) + abs(v[1]) + abs(v[2]);
}

void add(vi &v1, vi &v2) {
    for (int i = 0; i < v1.size(); i++)
        v1[i] += v2[i];
}

int32_t main() {
    string line;

    int n = 1000;
    string lines[1000];
    for (int i = 0; i < n; i++) getline(cin, lines[i]);

    vector<vi> PS(n), VS(n), AS(n);
    for (int i = 0; i < n; i++) {
        vs words = split(lines[i]);
        string p = words[0], v = words[1], a = words[2];
        p.pop_back();
        v.pop_back();
        p.pop_back();
        v.pop_back();
        a.pop_back();
        p = p.substr(3);
        v = v.substr(3);
        a = a.substr(3);
        
        vi P = parseInt(split(p, ','));
        vi V = parseInt(split(v, ','));
        vi A = parseInt(split(a, ','));

        PS[i] = P;
        VS[i] = V;
        AS[i] = A;
    }

    vi alive(n, 1);
    int iter = 0;
    const int LIMIT = 1000;
    do {
        map<vi, vi> coll;
        for (int i = 0; i < n; i++) {
            if (alive[i] == 0) continue;
            coll[PS[i]].push_back(i);
            add(VS[i], AS[i]);
            add(PS[i], VS[i]);
        }
        for (auto& it : coll) {
            if (it.second.size() == 1) continue;
            for (auto x : it.second) {
                alive[x] = 0;
            }
        }
        iter++;
    } while (iter < LIMIT);

    cout << accumulate(alive.begin(), alive.end(), 0) << endl;
}
