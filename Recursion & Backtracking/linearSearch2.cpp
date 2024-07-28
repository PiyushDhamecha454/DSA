#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
vector<int> found;
void linearSearch(vector<int>& v, int t, int i) {
    if (i == v.size()) return;
    else if (v[i] == t) found.push_back(i);
    linearSearch(v, t, i + 1);
}
vector<int> linearSearch2(vector<int>& v, int t, int i, vector<int> list) {
    if (i == v.size()) return list;
    else if (v[i] == t) list.push_back(i);
    return linearSearch2(v, t, i + 1, list);
}
vector<int> linearSearch3(vector<int>& v, int t, int i) {
    vector<int> list;
    if (i == v.size()) return list;
    else if (v[i] == t) list.push_back(i);
    vector<int> ans = linearSearch3(v, t, i + 1);
    list.insert(list.end(), ans.begin(), ans.end());
    return list;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n), u;
    for (int i = 0; i < n; i++) cin >> v[i];
    u = linearSearch3(v, 6, 0);
    for (int i = 0; i < u.size(); i++) cout << u[i] << ' ';
    cout << endl;
    u.clear();
    u = linearSearch3(v, 7, 0);
    for (int i = 0; i < u.size(); i++) cout << u[i] << ' ';
    cout << endl;
    u.clear();
}