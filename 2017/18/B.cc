#include "../../util.hpp"

queue<ll> q[2];
ll regs[2][26];
ll value(int p, string x) {
    if (isalpha(x[0])) return regs[p][x[0] - 'a'];
    return stoi(x);
}

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(0);

    string line;
    vector<vs> ins;
    while (getline(cin, line)) {
        vs words = split(line);
        ins.push_back(words);
    }
    int n = ins.size();
    regs[1]['p' - 'a'] = 1;


    ll times = 0;
    vi pos(2);
    while (true) {
        bool move = false;
        for (int p = 0; p < 2; p++) {
            while (pos[p] >= 0 && pos[p] < n) {
                int& i = pos[p];
                vs& words = ins[i];
                string a = words[0], b = words[1], c = words.back();
                if (a == "snd") {
                    q[1-p].push(value(p, b));
                    if (p == 1) times++;
                } else if (a == "set") {
                    regs[p][b[0] - 'a'] = value(p, c);
                } else if (a == "add") {
                    regs[p][b[0] - 'a'] += value(p, c);
                } else if (a == "mul") {
                    regs[p][b[0] - 'a'] *= value(p, c);
                } else if (a == "mod") {
                    regs[p][b[0] - 'a'] %= value(p, c);
                } else if (a == "rcv") {
                    if (!q[p].empty()) {
                        ll x = q[p].front(); q[p].pop();
                        regs[p][b[0] - 'a'] = x;
                    } else break;
                } else if (a == "jgz") {
                    if (value(p, b) > 0) {
                        i += value(p, c) - 1;
                    }
                }
                i++;
                move = true;
            }
        }
        if (!move) break;
    }
    cout << times << endl;
}

