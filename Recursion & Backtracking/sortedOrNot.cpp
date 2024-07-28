// g++ sortedOrNot.cpp
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
bool isSorted (vector<int>& v, int i) {
    if (i == v.size() - 1) return true;
    else if (v[i] > v[i + 1]) return false;
    return isSorted(v, i + 1);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        cout << isSorted(v, 0) << endl;
        sort(v.begin(), v.end());
        cout << isSorted(v, 0) << endl;
    }
}