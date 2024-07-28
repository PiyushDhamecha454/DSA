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
int findPivot(const vector<int>& v) {
    int l = 0, r = v.size() - 1, s;
    while (l <= r){
        int m = l + (r - l) / 2;
        if (m < r && v[m] > v[m + 1]) return m;
        if (m > l && v[m] < v[m - 1]) return m - 1;
        if (v[m] <= v[l]) r = m - 1;
        else l = m + 1;
    }
    return -1;
}
int search(const vector<int>& v, int target) {
    int pivot = findPivot(v);
    if (pivot == -1) return binarySearch(v, target, 0, v.size() - 1);
    if (v[pivot] == target) return pivot;
    if (target >= v[0]) return binarySearch(v, target, 0, pivot - 1);
    return binarySearch(v, target, pivot + 1, v.size() - 1);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << search({4,5,6,7,0,1,2}, 0) << endl;
}