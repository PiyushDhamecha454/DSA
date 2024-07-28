#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
bool palindrome(const string& s, int i) {
    if (i > s.size() / 2) return true;
    return s[i] == s[s.size() - i - 1] && palindrome(s, i + 1);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << palindrome("MALAYAAM", 0) << endl;
}