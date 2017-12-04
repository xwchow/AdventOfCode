#include "../../util.hpp"

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(0);

    string line;
    int res = 0;
    while (getline(cin, line)){
        vs w = split(line);
        map<string, int> mmap;
        for (string ww : w) {
            mmap[ww]++;
        }
        if (mmap.size() == w.size()) res++;
    }
    cout << res << endl;
}

