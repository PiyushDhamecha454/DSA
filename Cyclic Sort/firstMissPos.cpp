// g++ firstMissPos.cpp
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
int firstMissingPositive(vector<int>& v) {
    int n = v.size();
    int i = 0;
    while (i < n) {
        long c = (long)v[i] - 1;
        if (c >= 0 && c < n && v[i] != v[c]) swap(v[i], v[c]);
        else i++;
    }
    for (int x = 0; x < n; x++) if (x + 1 != v[x]) return x + 1;
    return n + 1;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {1,2,0};
    cout << firstMissingPositive(v) << endl;
}