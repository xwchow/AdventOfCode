#include "../../includes/util.hpp"

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const int n = 25;


int main() {
    string line;

    map<pii, int> grid;
    for (int i = 0; i < n; i++) {
        cin >> line;
        for (int j = 0; j < n; j++) {
            grid[{i, j}] = line[j] == '#';
        }
    }
    
    int k = 0;
    int x = n/2, y = n/2;

    int res = 0;
    for (int i = 0; i < 10000; i++) {
        int c = grid[{x, y}];
        if (c) {
            k = (k + 1) % 4;
        } else {
            k = (k - 1 + 4) % 4;
        }
        if (c == 0) {
            grid[{x, y}] = 1;
            res++;
        } else {
            grid[{x, y}] = 0;
        }
        x += dx[k];
        y += dy[k];
    }
    cout << res << endl;
}
