#include "../../includes/util.hpp"

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(0);
    int x;
    vi arr;
    while (cin >> x) {
        arr.push_back(x);
    }
    int steps = 0;
    int pos = 0;
    int n = (int)arr.size();
    while (pos >= 0 && pos < n) {
        steps++;
        pos += arr[pos]++;
    }
    cout << steps << endl;
}
