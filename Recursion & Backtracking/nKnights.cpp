#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void display(vector<vector<bool>>& v) {
    for (const vector<bool>& vi : v) {
        for (bool vij : vi) {
            if (vij == true) cout << "K ";
            else cout << "X ";
        }
        cout << endl;
    }
}

bool isValid(vector<vector<bool>>& v, int i, int j) {
    return (i >= 0 && i < v.size() && j >= 0 && j < v[0].size()); // Corrected to use v[0].size() for column check
}

bool isSafe(vector<vector<bool>>& v, int i, int j) {
    if (isValid(v, i - 2, j - 1) && v[i - 2][j - 1]) return false;
    if (isValid(v, i - 2, j + 1) && v[i - 2][j + 1]) return false;
    if (isValid(v, i - 1, j - 2) && v[i - 1][j - 2]) return false;
    if (isValid(v, i - 1, j + 2) && v[i - 1][j + 2]) return false;
    return true;
}

int nKnights(vector<vector<bool>>& v, int i, int j, int knights) {
    if (knights == 0) {
        display(v);
        cout << endl;
        return 1;
    }
    if (i == v.size() && j == 0) return 0;
    
    int c = 0;
    if (j == v[0].size()) {
        c += nKnights(v, i + 1, 0, knights);
    } else {
        if (isSafe(v, i, j)) {
            v[i][j] = true;
            c += nKnights(v, i, j + 1, knights - 1);
            v[i][j] = false;
        }
        c += nKnights(v, i, j + 1, knights);
    }
    
    return c;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<bool>> v(n, vector<bool>(n, false));
    cout << nKnights(v, 0, 0, 4) << endl;
}
