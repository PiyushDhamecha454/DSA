#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
void skip (string s, char c, int i) {
    if (i == s.size()) return;
    else if (s[i] == c) skip(s, c, i + 1);
    else {
        cout << s[i];
        skip(s, c, i + 1);
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    skip(s, 'A', 0);
    cout << endl;
}