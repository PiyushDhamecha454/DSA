#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
int ceiling(const vector<int> &v, int target) {
    int l = 0, r = v.size() - 1;
    int c = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (v[m] == target) return v[m];
        else if (v[m] < target) l = m + 1;
        else {
            c = v[m];
            r = m - 1;
        }
    }
    return c;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << ceiling({2, 3, 5, 9, 14, 16, 18}, 15) << endl;
}