#include "../../util.hpp"

int n = 256;
string grid[128];
string HEX = "0123456789abcdef";
int G[128][128];
int vis[128][128];

void rev(vi &arr, int id, int x) {
    for (int i = 0; i < x/2; i++) {
        int L = (id + i) % n;
        int R = (id + x - 1 - i) % n + n % n;
        swap(arr[L], arr[R]);
    }
}

int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};

void dfs(int i, int j, int region) {
    vis[i][j] = region;
    for (int k = 0; k < 4; k++) {
        int i2 = i +dx[k], j2 = j+dy[k];
        if (i2 < 0 || i2 >= 128 || j2 < 0 || j2 >= 128) continue;
        if (!vis[i2][j2] && G[i][j])
            dfs(i2, j2, region);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(0);
    string input; cin >> input;
    
    for (int i = 0; i < 128; i++) {
        grid[i] = input;
        grid[i] += '-';
        grid[i] += to_string(i);
    }

    int sum = 0;
    for (int row = 0; row < 128; row++) {
        vi lens;
        for (char c : grid[row]) lens.push_back(c);
        lens.push_back(17);
        lens.push_back(31);
        lens.push_back(73);
        lens.push_back(47);
        lens.push_back(23);

        vi arr(n);
        iota(arr.begin(), arr.end(), 0);
        int id = 0, skip = 0;
        for (int round = 0; round < 64; round++) {
            for (int x : lens) {
                rev(arr, id, x);
                id = (id + x + skip) % n;
                skip++;
            }
        }

        string output;
        ostringstream out;
        for (int i = 0; i < n; i += 16) {
            int val = 0;
            for (int j = 0; j < 16; j++) {
                val ^= arr[i + j];
            }
            out << setfill('0') << setw(2) << hex << val;
        }
        output = out.str();
        for (int i = 0; i < 32; i++) {
            int hex = HEX.find(output[i]);
            int b = (1 << 3);
            for (int j = 0; j < 4; j++) {
                if (hex & b) G[row][4*i + j] = 1;
                b >>= 1;
            }
        }
    }

    int region = 0;
    for (int i = 0; i < 128; i++)
        for (int j = 0; j < 128; j++)
            if (vis[i][j] == 0 && G[i][j])
                dfs(i, j, ++region);
    
    cout << region << endl;
}

