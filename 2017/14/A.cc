#include "../../util.hpp"

int n = 256;
string grid[128];

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(0);
    string input; cin >> input;
    
    for (int i = 0; i < 128; i++) {
        grid[i] = input;
        grid[i] += '-';
        grid[i] += to_string(i);
    }

    int sum = 0;
    for (int i = 0; i < 128; i++) {
        string output = knotHash(grid[i]);
        for (char c : output) {
            sum += __builtin_popcount(HEX.find(c));
        }
    }
    cout << sum << endl;
}

