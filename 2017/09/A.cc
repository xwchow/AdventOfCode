#include "../../includes/util.hpp"

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(0);
    string line;
    cin >> line;
    int open = 0;
    int n = line.size();

    bool garbage = false;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        char c = line[i];
        if (!garbage) {
            if (c == '{') {
                open++;
                sum += open;
            } else if (c == '}') {
                open--;
            } else if (c == '<') {
                garbage = true;
            }
        } else {
            if (c == '!') {
                i++;
            } else if (c == '>') {
                garbage = false;
            } 
        }
    }
    cout << sum << endl;
}

