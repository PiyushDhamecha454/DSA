#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
void dice(string s, int n) {
    //Obviously, n should be below than 7 and more than 0
    if (n == 0) {
        cout << s << endl;
        return;
    }
    for (int i = 1; i <= n; i++) dice(s + to_string(i), n - i);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    dice("", 5);
}