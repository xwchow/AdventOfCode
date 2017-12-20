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

    int best = LLONG_MAX / 2;
    int part = -1;

    const int LIMIT = 1000;
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

        for (int iter = 0; iter < LIMIT; iter++){
            add(V, A);
            add(P, V);
        }

        if (man(P) < best) {
            best = man(P);
            part = i;
        }
    }
    cout << part << endl;
}
