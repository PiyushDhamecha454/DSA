#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
int peakIndexInMountainArray(const vector<int>& v) {
    int s = 0, e = v.size() - 1;
    while (s < e) {
        int m = s + (e - s) / 2;
        if (v[m] < v[m + 1]) s = m + 1;
        else if (v[m] > v[m + 1]) e = m;
    }
    return s;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << peakIndexInMountainArray({0, 1, 2, 0}) << endl;
}