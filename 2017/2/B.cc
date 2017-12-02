#include "../../util.hpp"

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(0);

    string line;
    int sum = 0;
    while (getline(cin, line)) {
        vi v = split<int>(line);
        for (int x : v) {
            for (int y : v) {
                if (x > y && x % y == 0) sum += x/y;
            }
        }
    }
    cout << sum << endl;
}

