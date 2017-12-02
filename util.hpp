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

bool startsWith(const string& line, string s);

bool isInt(const std::string & s);
vi parseInt(const vector<string>& words);
vector<char> parseChar(const vector<string>& words);

