#include "../../includes/util.hpp"

ll regs[26];
ll value(string x) {
    if (isalpha(x[0])) return regs[x[0] - 'a'];
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

    int res = 0;
    for (int i = 0; i >= 0 && i < n; i++) {
        vs& words = ins[i];
        string a = words[0], b = words[1], c = words.back();
        if (a == "snd") {

        } else if (a == "set") {
            regs[b[0] - 'a'] = value(c);
        } else if (a == "add") {
            regs[b[0] - 'a'] += value(c);
        } else if (a == "sub") {
            regs[b[0] - 'a'] -= value(c);
        } else if (a == "mul") {
            regs[b[0] - 'a'] *= value(c);
            res++;
        } else if (a == "mod") {
            regs[b[0] - 'a'] %= value(c);
        } else if (a == "rcv") {

        } else if (a == "jgz") {
            if (value(b) > 0) {
                i += value(c) - 1;
            }
        } else if (a == "jnz") {
            if (value(b) != 0) {
                i += value(c) - 1;
            }
        }
    }
    cout << res << endl;
}

