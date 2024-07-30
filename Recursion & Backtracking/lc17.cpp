#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
map<string, vector<string>> m = {{"2", {"a", "b", "c"}},
                                 {"3", {"d", "e", "f"}},
                                 {"4", {"g", "h", "i"}},
                                 {"5", {"j", "k", "l"}},
                                 {"6", {"m", "n", "o"}},
                                 {"7", {"p", "q", "r", "s"}},
                                 {"8", {"t", "u", "v"}},
                                 {"9", {"w", "x", "y", "z"}}};
vector<string> dialup2(string s, string t) {
    if (t.empty()) return {s};
    string digit = string(1, t[0]);
    vector<string> p;
    for (const string& c : m[digit]) {
        vector<string> r = dialup2(s + c, t.substr(1));
        p.insert(p.end(), r.begin(), r.end());
    }
    return p;
}
vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    return dialup2("", digits);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> v;
    v = letterCombinations("");
    for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
}