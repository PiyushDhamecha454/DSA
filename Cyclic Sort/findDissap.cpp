// g++ findDissap.cpp
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
vector<int> findDisappearedNumbers(vector<int>& v) {
    for (int i = 0; i < v.size();) {
        if (v[i] != i + 1 && v[v[i] - 1] != v[i]) swap(v[i], v[v[i] - 1]);
        else i++;
    }
    vector<int> u;
    for (int i = 0; i < v.size(); i++) if (v[i] != i + 1) u.push_back(i + 1);
    return u;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {4,3,2,7,8,2,3,1};
    vector<int> u = findDisappearedNumbers(v);
    for (int x : u) cout << x << ' ';
    cout << endl;
}