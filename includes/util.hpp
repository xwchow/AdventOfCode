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

const string HEX = "0123456789abcdef";

vector<string> split(const string& inp, char delim=' ');
bool startsWith(const string& line, string s);

bool isInt(const std::string & s);
vi parseInt(const vector<string>& words);
vector<char> parseChar(const vector<string>& words);

void rev(vi &arr, int id, int x);
string knotHash(const string& input, int k = 256, int rounds = 64);

string join(vs lines, string str);
string join(vs lines, char c);
