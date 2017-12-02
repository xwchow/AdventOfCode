#include "../../util.hpp"

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(0);

    string line;
    int sum = 0;
    while (getline(cin, line)) {
        vi v = split<int>(line);
        sum += *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
    }
    cout << sum << endl;
}

