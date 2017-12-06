#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

#define debug(x) cerr << #x << " = " << (x) << endl;
template<typename T>
ostream& operator<<(ostream& o, vector<T>& v) {
    for (auto& x : v) o << x << ' ';
    return o;
}

vector<string> split(const string& inp, char delim=' ');
bool startsWith(const string& line, string s);

bool isInt(const std::string & s);
vi parseInt(const vector<string>& words);
vector<char> parseChar(const vector<string>& words);

