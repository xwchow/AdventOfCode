#include "../../includes/util.hpp"

const int ITER = 18;
const int N = 5000;
vs grid(N, string(N, '.'));
vs tmp(N, string(N, '.'));

string get(int i, int j, int sz) {
    string pat;
    for (int ii = i; ii < i + sz; ii++) {
        for (int jj = j; jj < j + sz; jj++) 
            pat += grid[ii][jj];
        if (ii != i + sz - 1) pat += "/";
    }
    return pat;
}

void fill(int i, int j, string to, int sz, vs& grid = tmp) {
    vs lines = split(to, '/');
    for (int ii = i; ii < i + sz; ii++) 
        for (int jj = j; jj < j + sz; jj++) 
            grid[ii][jj] = lines[ii - i][jj - j];
}

string flip(string line) {
    vs lines = split(line, '/');
    for (string& line : lines) reverse(line.begin(), line.end());
    return join(lines, '/');
}

string rotate(string line) {
    vs lines = split(line, '/');
    int n = lines.size();
    vs nxt(n, string(n, '#'));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            nxt[i][j] = lines[n-1-j][i];
    return join(nxt, '/');
}

int main() {
    fill(0, 0, ".#./..#/###", 3, grid);
    
    map<string, string> conv;
    string line;
    while (getline(cin, line)) {
        vs words = split(line);
        for (int i = 0; i < 4; i++) {
            words[0] = rotate(words[0]);
            conv[words[0]] = words[2];
            conv[flip(words[0])] = words[2];
        }
    }

    int n = 3;
    for (int it = 0; it < ITER; it++) {
        int sz = (n % 2 == 0) ? 2 : 3;
        for (int i = 0; i < n; i += sz) {
            for (int j = 0; j < n; j += sz) {
                string pat = get(i, j, sz);
                assert(conv.count(pat));
                fill(i / sz * (sz + 1), j / sz * (sz + 1), conv[pat], sz + 1);
            }
        }
        n = n / sz * (sz + 1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                grid[i][j] = tmp[i][j];
        debug(n);
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sum += (grid[i][j] == '#');
    cout << sum << endl;
}
