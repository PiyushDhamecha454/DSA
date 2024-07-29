// g++ subsequence.cpp
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
void subsequence(string s, string up) {
    if (up.size() == 0) {
        cout << s << endl;
        return;
    }
    char ch = up[0];
    subsequence(s + ch, up.substr(1));
    subsequence(s, up.substr(1));
}
vector<string> subseq(string s, string up) {
    if (up.size() == 0) {
        vector<string> list = {s};
        return list;
    }
    char ch = up[0];
    vector<string> l = subseq(s + ch, up.substr(1));
    vector<string> r = subseq(s, up.substr(1));
    l.insert(l.end(), r.begin(), r.end());
    return l;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> s1 = subseq("", "abc");
    for (auto it : s1) cout << it << ' ';
    cout << endl;
}