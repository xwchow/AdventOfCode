#include "util.hpp"

bool startsWith(const string& line, string s) {
    return line.substr(0, s.size()) == s; 
}

// https://stackoverflow.com/questions/2844817/how-do-i-check-if-a-c-string-is-an-int
bool isInt(const std::string & s)
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
