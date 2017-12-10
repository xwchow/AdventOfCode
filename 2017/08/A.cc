#include "../../util.hpp"

map<string, int> regs;
bool eval(vs& words) {
    string op = words[5];
    int val = regs[words[4]];
    int cmp = stoi(words.back());
    if (op == ">") return val > cmp;
    else if (op == "<") return val < cmp;
    else if (op == ">=") return val >= cmp;
    else if (op == "<=") return val <= cmp;
    else if (op == "!=") return val != cmp;
    else if (op == "==") return val == cmp;
}

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(0);

    string line;

    while (getline(cin, line)) {
        vs words = split(line);
        if (eval(words)) {
            regs[words[0]] += stoi(words[2]) * (words[1] == "inc" ? 1 : -1);
        }
    }
    
    int Ma = INT_MIN;
    for (auto& it : regs) {
        Ma = max(Ma, it.Y);
    }    
    cout << Ma << endl;
}

