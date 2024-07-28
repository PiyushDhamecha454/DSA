#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
int cZ(const vector<int>& v, int i) {
    if (v[i] == 0) return v.size() - i;
    return cZ(v, i + 1);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << cZ({1,1,1,1,0,0,0,0,0,0}, 0) << endl;
}