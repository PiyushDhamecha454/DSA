#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
int linearSearch(vector<int>& v, int t, int i) {
    if (i == v.size()) return -1;
    else if (v[i] == t) return i;
    return linearSearch(v, t, i + 1);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << linearSearch(v, 6, 0) << endl << linearSearch(v, 7, 0) << endl;
}