#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
int fib(int x, vector<int>& m) {
    if (x < 2) return x;
    if (m[x] != -1) return m[x];
    m[x] = fib(x - 1, m) + fib(x - 2, m);
    return m[x];    
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> m(8, -1);
    cout << fib(7, m) << endl;
}