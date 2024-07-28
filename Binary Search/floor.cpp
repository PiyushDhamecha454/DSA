#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
int floor(const vector<int> &v, int target) {
    int l = 0, r = v.size() - 1;
    int f = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (v[m] == target) return v[m];
        else if (v[m] > target) r = m - 1;
        else {
            f = v[m];
            l = m + 1;
        }
    }
    return f;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << floor({2, 3, 5, 9, 14, 16, 18}, 1) << endl;
}