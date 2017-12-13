#include "../../util.hpp"

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(0);

    string line;
    vector<pii> v;
    while (getline(cin, line)) {
        stringstream ss(line);
        char c;
        int depth, range;
        ss >> depth >> c >> range;
        v.emplace_back(depth, range);
    }

    for (int delay = 0; ;delay++) {
        bool caught = false;
        for (auto p : v) {
            int depth, range;
            tie(depth, range) = p;

            int dist = depth + delay;
            dist %= (2 * (range - 1));
            
            int pos = 0;
            bool down = true;

            for (int i = 0; i < dist; i++) {
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
                caught = true;
                break;
            }
        }
        if (!caught) {
            cout << delay << endl;
            return 0;
        }
    }


}

