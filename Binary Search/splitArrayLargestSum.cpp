//g++ splitArrayLargestSum.cpp
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
int splitArray(const vector<int>& v, int k) {
    int s = 0, e = 0;
    for (int i = 0; i < v.size(); i++) {
        s = max(s, v[i]);
        e += v[i];
    }
    //cout << "s = " << s << " & e = " << e << endl;
    while (s < e) {
        int m = s + (e - s) / 2;
        int sum = 0, p = 1;
        for (int x : v) {
            if (sum + x > m) {
                sum = x;
                p++;
            }
            else sum += x;
        }
        if (p > k) s = m + 1;
        else e = m;
    }
    return e;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << splitArray({7, 2, 5, 10, 8}, 2) << endl;
}