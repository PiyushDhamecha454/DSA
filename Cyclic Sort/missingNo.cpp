#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
int missingNumber(const vector<int>& nums) {
    int n = nums.size();
    int s1 = 0, s2 = (n * (n + 1)) / 2;
    for (int x : nums) s1 += x;
    cout << s2 << ' ' << s1 << endl;
    return s2 - s1;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << missingNumber({3, 0, 1}) << endl;
    cout << missingNumber({0, 1}) << endl;
    cout << missingNumber({9, 6, 4, 2, 3, 5, 7, 0, 1}) << endl;
}