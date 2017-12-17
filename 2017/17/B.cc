#include "../../util.hpp"

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    int pos = 0;

    int last = 0;
    int k = 50000000;

    for (int i = 1; i <= k; i++) {
        pos = (pos + n) % i;
        pos++;
        if (pos == 1) last = i;
    }
    cout << last << endl;
}

