#include "../../includes/util.hpp"

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    int k = 2017;
    
    int pos = 0;
    vi v = {0};
    int last = 0;
    for (int i = 1; i <= k; i++) {
        pos = (pos + n + 1) % v.size();
        v.insert(v.begin() + pos, i);
        last = v[(pos + 1) % v.size()];
    }
    cout << last << endl;
}

