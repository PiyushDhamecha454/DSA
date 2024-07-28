#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
int orderAgnosticBS(const vector<int>& arr, int target, int start, int end) {
    bool isAsc = arr[start] < arr[end];
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) return mid;
        if (isAsc) {
            if (target < arr[mid]) end = mid - 1;
            else start = mid + 1;
        } else {
            if (target > arr[mid]) end = mid - 1;
            else start = mid + 1;
        }
    }
    return -1;
}
int findInMountainArray(const vector<int>& v, int target) {
    int s = 0, e = v.size() - 1;
    while (s < e) {
        int m = s + (e - s) / 2;
        if (v[m] < v[m + 1]) s = m + 1;
        else e = m;
    }
    int c = orderAgnosticBS(v, target, 0, s);
    if (c != -1) return c;
    return orderAgnosticBS(v, target, s + 1, v.size() - 1);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {0, 5, 3, 1};
    cout << v[findInMountainArray(v, 1)] << endl;
}