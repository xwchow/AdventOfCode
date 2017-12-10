#include "../../util.hpp"

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(0);

    int n = 16;
    vi arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    map<vi, int> seen;
    int cnt = 0;
    while (!seen.count(arr)) {
        cnt++;
        seen[arr] = 1;
        auto idx = max_element(arr.begin(), arr.end()) - arr.begin();
        int Ma = arr[idx];
        arr[idx] = 0;
        for (int j = 0; j < Ma; j++) {
            arr[(idx + 1 + j) % n]++;
        }
    }
    cout << cnt << endl;
}

