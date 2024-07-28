//g++ firstAndLastPositionsInSortedArray.cpp
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
int search (const vector<int>& v, int target, bool findStart) {
    int ans = -1;
    int l = 0, r = v.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (target < v[m]) r = m - 1;
        else if (target > v[m]) l = m + 1;
        else {
            ans = m;
            if (findStart) r = m - 1;
            else l = m + 1;
        }
    }
    return ans;
}
vector<int> searchRange(const vector<int>& v, int target) {
    return {search(v, target, true), search(v, target, false)};
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = searchRange({5, 7, 7, 8, 8, 10}, 8);
    cout << v[0] << ' ' << v[1] << '\n';
}