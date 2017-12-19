#include "../../includes/util.hpp"

string grid[222];
int n, m;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != ' ';
}

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(0);
    
    string line;
    n = 0;
    while (getline(cin, line)) {
        grid[n++] = line;
    }

    m = grid[0].size();
    int x = 0, y = 0;
    for (int j = 0; j < m; j++) {
        if (grid[0][j] != ' ') {
            x = 0;
            y = j;
            break;
        }
    }

    string res;
    int k = 0, steps = 0;
    while (1) {
        if (!valid(x, y)) break;
        char c = grid[x][y];
        steps++;
        if (isalpha(c)) res += c;
        if (c == '+') {
            if (valid(x + dx[(k + 1) % 4], y + dy[(k + 1) % 4])) {
                k = (k + 1) % 4;
            } else {
                k = (k - 1 + 4) % 4;
            }
        }
        x += dx[k];
        y += dy[k];
    }
    cout << steps << endl;
    cout << res << endl;
}

