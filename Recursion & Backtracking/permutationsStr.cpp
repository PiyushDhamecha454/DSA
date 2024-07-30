#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
vector<string> permutation(string s, string up) {
    if (up.size() == 0) return {s};
    char ch = up[0];
    vector<string> v;
    for (int i = 0; i <= s.size(); i++) {
        vector<string> temp = permutation(s.substr(0, i) + ch + s.substr(i, s.size()), up.substr(1));
        v.insert(v.end(), temp.begin(), temp.end());
    }
    return v;
}
int countPermutation(string s, string up) {
    if (up.size() == 0) return 1;
    char ch = up[0];
    int c = 0;
    for (int i = 0; i <= s.size(); i++) c += countPermutation(s.substr(0, i) + ch + s.substr(i, s.size()), up.substr(1));
    return c;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    vector<string> v = permutation("", "abcd");
    for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
    cout << countPermutation("", "abcd") << endl;
}