#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
void nto1(int n) {
    if (n == 0) return;
    nto1(n - 1);
    cout << n << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    nto1(5);
}