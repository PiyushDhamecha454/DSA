#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
vector<int> merge(vector<int>& v, int n, vector<int>& u, int m) {
    vector<int> w(m + n);
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (v[i] < u[j]) w[k++] = v[i++];
        else w[k++] = u[j++];
    }
    while (i < n) w[k++] = v[i++];
    while (j < m) w[k++] = u[j++];
    return w;
}
vector<int> sort(vector<int>& w, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        vector<int> v(w.begin(), w.begin() + m);
        vector<int> u(w.begin() + m + 1, w.end());
        v = sort(v, 0, v.size() - 1);
        u = sort(u, 0, u.size() - 1);
        return merge(v, v.size(), u, u.size());
    }
    return {};
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> w(m + n);
    for (int i = 0; i < n + m; i++) cin >> w[i];
    vector<int> w = sort(w, 0, m + n - 1);
    for (int i = 0; i < m + n; i++) cout << w[i] << ' ';
    cout << endl;
}