#include "../../util.hpp"

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(0);

    string line; cin >> line;
    vs words = split(line, ',');
    string progs = "abcdefghijklmnop";
    for (string w : words) {
        if (w[0] == 's') {
            int rot = stoi(w.substr(1)) % 16;
            rotate(progs.begin(), progs.begin() + 16 - rot, progs.end());
        } else if (w[0] == 'x') {
            vi v = parseInt(split(w.substr(1), '/'));
            int A = v[0], B = v[1];
            swap(progs[A], progs[B]);
        } else if (w[0] == 'p') {
            char a = w[1], b = w[3];
            int A = progs.find(a), B = progs.find(b);
            swap(progs[A], progs[B]);
        }
    }
    cout << progs << endl;
}

