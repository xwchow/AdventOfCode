#include "../../includes/util.hpp"

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(0);

    string line;

    int sum = 0;
    while (getline(cin, line)) {
        stringstream ss(line);
        char c;
        int depth, range;
        ss >> depth >> c >> range;

        int pos = 0;
        bool down = true;

        
        for (int i = 0; i < depth; i++) {
            if (down) {
                if (pos == range-1) {
                    pos--;
                    down = false;
                } else 
                    pos++;
            } else {
                if (pos == 0) {
                    pos++;
                    down = true;
                } else 
                    pos--;                
            }
        }
        if (pos == 0 || range == 1) {
            sum += depth * range;
            cerr << depth << ' ' << range << endl;
        }
    }
    cout << sum << endl;

}

