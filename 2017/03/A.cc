#include "../../includes/util.hpp"


int grid[1000][1000];
int n; 

void f(int x, int y, int i) {
    if (i == n) {
        cout << abs(x) + abs(y) << endl;
    }
    grid[x + 500][y + 500] = i;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;

    int x = 0, y = 0;
    for (int lvl = 0, i = 1; i <= n; lvl++) {
        int r = 2 * lvl;
        f(x, y, i++);
        vi moves = {r - 1, r, r, r};
        for (int k = 0; k < 4; k++) {
            for (int j = 0; j < moves[k]; j++) {
                x += dx[k]; y += dy[k];
                f(x, y, i++);
            }
        }
        y++;
    }
}

