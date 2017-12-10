#include "../../util.hpp"
int n = 256;
void rev(vi &arr, int id, int x) {
    for (int i = 0; i < x/2; i++) {
        int L = (id + i) % n;
        int R = (id + x - 1 - i) % n + n % n;
        swap(arr[L], arr[R]);
    }
}

string HEX = "0123456789abcdef";
string toHex(int val) {
    string res;
    res += HEX[val / 16];
    res += HEX[val % 16];
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(0);
    string line; cin >> line;
    vi lens;
    for (char c : line) lens.push_back(c);
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

    string hash;
    for (int i = 0; i < n; i += 16) {
        int val = 0;
        for (int j = 0; j < 16; j++) {
            val ^= arr[i + j];
        }
        hash += toHex(val);
    }
    cout << hash << endl;
    
}

