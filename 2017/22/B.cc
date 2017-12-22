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
            grid[{i, j}] = (line[j] == '#') ? 2 : 0;
        }
    }
    
    int k = 0;
    int x = n/2, y = n/2;

    int res = 0;
    for (int i = 0; i < 10000000; i++) {
        int &c = grid[{x, y}];
        if (c == 0) k = (k - 1 + 4) % 4;
        else if (c == 1) ;
        else if (c == 2) k = (k + 1) % 4;
        else k = (k + 2) % 4;

        c = (c + 1) % 4;
        if (c == 2) res++;
        x += dx[k];
        y += dy[k];
    }
    cout << res << endl;
}
