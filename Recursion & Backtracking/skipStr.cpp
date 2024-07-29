#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
bool startsWith(const string& s, const string& target) {
    if (s.size() < target.size()) return false;
    return s.compare(0, target.size(), target) == 0;
}
string skipStr (const string& s, const string& target, int i) {
    if (i >= s.size()) return "";
    if (startsWith(s.substr(i), target)) return skipStr(s, target, i + target.size());
    else return s[i] + skipStr(s, target, i + 1);
}
string skipSpecificStr (const string& s, int i) {
    if (i >= s.size()) return "";
    if (startsWith(s.substr(i), "app") && !startsWith(s.substr(i), "apple")) return skipSpecificStr(s, i + 3);
    else return s[i] + skipSpecificStr(s, i + 1);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s = "appleballappbanana";
    cout << skipSpecificStr(s, 0) << endl;
}