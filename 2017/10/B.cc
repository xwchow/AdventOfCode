#include "../../util.hpp"

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(0);
    string line; cin >> line;
    string output = knotHash(line);
    cout << output << endl;    
}

