#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define debug(x) cerr << #x << " = " << (x) << endl;
template<typename T>
ostream& operator<<(ostream& o, vector<T>& v) {
    for (auto& x : v) o << x << ' ';
    return o;
}

template<typename T>
vector<T> split(const string& inp, char delim=',') {
    vector<T> res;
    istringstream ss(inp);
    T value;
    while (ss >> value) {
        res.push_back(value);
        if (ss.peek() == delim)
            ss.ignore();
    }
    return res;
}

int main(){
    std::ios_base::sync_with_stdio(false); cin.tie(0);

    string s; cin >> s;
    int n = s.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == s[(i+1)%n]) {
            res += s[i] - '0';
        }
    }
    cout << res << endl;
}
