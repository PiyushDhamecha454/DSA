#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
void display (vector<vector<bool>>& v) {
    for (vector<bool> vi : v) {
        for (bool vij : vi) {
            if (vij == true) cout << "Q ";
            else cout << "X ";
        }
        cout << endl;
    }
}
bool isSafe (vector<vector<bool>>& v, int i, int j) {
    for (int x = 0; x < i; x++) if (v[x][j]) return false;
    int maxLeft = min(i, j);
    for (int x = 1; x <= maxLeft; x++) if (v[i - x][j - x]) return false;
    int maxRight = min(i, (int)(v.size() - j - 1));
    for (int x = 1; x <= maxRight; x++) if (v[i - x][j + x]) return false;
    return true;
}
int nQueens (int i, vector<vector<bool>>& v) {
    if (i == v.size()) {
        display(v);
        cout << endl;
        return 1;
    }
    int c = 0;
    for (int j = 0; j < v.size(); j++) {
        if (isSafe(v, i, j)) {
            v[i][j] = true;
            c += nQueens(i + 1, v);
            v[i][j] = false;
        }
    }
    return c;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<bool>> v(n, vector<bool>(n, false));
    cout << nQueens(0, v) << endl;
}