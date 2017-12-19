#include "../../includes/util.hpp"

int main(){
    std::ios_base::sync_with_stdio(false); cin.tie(0);

    string s; cin >> s;
    int n = s.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == s[(i+n/2)%n]) {
            res += s[i] - '0';
        }
    }
    cout << res << endl;
}
