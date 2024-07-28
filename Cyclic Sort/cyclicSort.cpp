#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
void cyclicSort(vector<int>& v) {
    for (int i = 0; i < v.size();) {
        if (v[i] == i + 1) i++;
        else swap(v[i], v[v[i] - 1]);
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {3, 5, 2, 1, 4};
    cyclicSort(v);
    for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
    cout << endl;
}