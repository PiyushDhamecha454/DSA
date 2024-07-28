#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
int i = 0;
vector<vector<int>> memo(3, vector<int>(3, -1));
int paths(int i, int j, int n) {
    if (i == n - 1 && j == n - 1) return 1;
    if (memo[i][j] != -1) return memo[i][j];
    int c = 0;
    if (i < n - 1) c += paths(i + 1, j, n);
    if (j < n - 1) c += paths(i, j + 1, n);
    return memo[i][j] = c;
}
int paths2(int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) dp[i][0] = 1;
    for (int j = 0; j < n; j++) dp[0][j] = 1;
    for (int i = 1; i < n; i++) for (int j = 1; j < n; ++j) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    return dp[n - 1][n - 1];
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << paths2(3) << endl;
}