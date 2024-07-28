//g++ findPositionInInfinte.cpp
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
int binarySearch (const vector<int>& v, int target, int l, int r) {
    int s = l, e = r;
    while (s <= e) {
        int m = s + (e - s) / 2;
        if (target < v[m]) e = m - 1;
        else if (target > v[m]) s = m + 1;
        else return m;
    }
    return -1;
}
int inf(const vector<int>& v, int target) {
    int s = 0, e = 1;
    while (target > v[e]) {
        int newS = e + 1;
        e = e + (e - s + 1) * 2;
        s = newS;
    }
    return binarySearch(v, target, s, e);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << inf({3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170}, 10) << endl;
}