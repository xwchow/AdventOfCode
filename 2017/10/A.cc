#include "../../util.hpp"
int n = 256;
void rev(vi &arr, int id, int x) {
    for (int i = 0; i < x/2; i++) {
        int L = (id + i) % n;
        int R = (id + x - 1 - i) % n + n % n;
        swap(arr[L], arr[R]);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(0);
    string line;
    cin >> line;
    vi lens = parseInt(split(line, ','));


    vi arr(n);
    iota(arr.begin(), arr.end(), 0);
    
    int id = 0, skip = 0;
    for (int x : lens) {
        rev(arr, id, x);
        id = (id + x + skip) % n;
        skip++;
    }
    cout << arr[0] * arr[1] << endl;
}

