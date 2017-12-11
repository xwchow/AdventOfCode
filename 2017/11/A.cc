#include "../../util.hpp"

const string DIR[] = {"n", "ne", "se", "s", "sw", "nw"};
int dx[] = {-2, -1, 1, 2, 1, -1};
int dy[] = {0, 1, 1, 0, -1, -1};

int steps(int x, int y) {
    x = abs(x);
    y = abs(y);
    int m = min(x, y);
    x -= m;
    y -= m;
    int sum = m + x / 2 + y;
    return sum;
}

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(0);

    string line;
    cin >> line;
    vs words = split(line, ',');

    int x = 0, y = 0;
    int Ma = 0;
    for (string w : words) {
        int idx = find(DIR, DIR + 6, w) - DIR;
        x += dx[idx];
        y += dy[idx];
    }
    
    cout << steps(x, y) << endl;
}

