#include "util.hpp"

vector<string> split(const string& inp, char delim) {
    bool ws = delim == ' ';
    vector<string> res;
    string cur;
    for (char c : inp) {
        if (c == delim || (ws && isspace(c))) {
            if (cur.size() || !ws) res.push_back(cur);
            cur = "";
        }
        else cur += c;
    }
    if (cur.size() || !ws) res.push_back(cur);
    return res;
}

bool startsWith(const string& line, string s) {
    return line.substr(0, s.size()) == s; 
}

// https://stackoverflow.com/questions/2844817/how-do-i-check-if-a-c-string-is-an-int
bool isInt(const std::string& s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

   char * p ;
   strtol(s.c_str(), &p, 10) ;

   return (*p == 0) ;
}

vi parseInt(const vector<string>& words) {
    vi res;
    for (auto &w : words) {
        if (isInt(w)) res.push_back(stoi(w));
    }
    return res;
}

vector<char> parseChar(const vector<string>& words) {
    vector<char> res;
    for (auto &w : words) {
        if (w.size() == 1 && isalpha(w[0])) res.push_back(w[0]);
    }
    return res;
}

void rev(vi &arr, int id, int x) {
    int n = (int)arr.size();
    for (int i = 0; i < x/2; i++) {
        int L = (id + i) % n;
        int R = (id + x - 1 - i) % n + n % n;
        swap(arr[L], arr[R]);
    }
}

string knotHash(const string& input, int k, int rounds) {
    vi lens;
    for (char c : input) lens.push_back(c);
    lens.insert(lens.end(), {17, 31, 73, 47, 23});

    vi arr(k);
    iota(arr.begin(), arr.end(), 0);
    int id = 0, skip = 0;
    for (int round = 0; round < rounds; round++) {
        for (int x : lens) {
            rev(arr, id, x);
            id = (id + x + skip) % k;
            skip++;
        }
    }

    ostringstream out;
    for (int i = 0; i < k; i += 16) {
        int val = 0;
        for (int j = 0; j < 16; j++) {
            val ^= arr[i + j];
        }
        out << setfill('0') << setw(2) << hex << val;
    }
    return out.str();
}

string join(vs lines, string str) {
    string res;
    int n = lines.size();
    for (int i = 0; i < n; i++) {
        res += lines[i];
        if (i != n-1) res += str;
    }
    return res;
}

string join(vs lines, char c) {
    return join(lines, string(1, c));
}
