#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
//(0, 0) -> (n, n) Only Right and Down
void printPaths(int i, int j, int n, string s) {
    if (i == n - 1 && j == n - 1) {
        cout << s << endl;
        return;
    }
    if (i < n - 1) printPaths(i + 1, j, n, s + "Down ");
    if (j < n - 1) printPaths(i, j + 1, n, s + "Right ");
}
int noOfPaths(int i, int j, int n) {
    if (i == n - 1 && j == n - 1) return 1;
    int c = 0;
    if (i < n - 1) c += noOfPaths(i + 1, j, n);
    if (j < n - 1) c += noOfPaths(i, j + 1, n);
    return c;
}
//(0, 0) -> (n, n) Only Right, Down and Diagonally
void printPaths2(int i, int j, int n, string s) {
    if (i == n - 1 && j == n - 1) {
        cout << s << endl;
        return;
    }
    if (i < n - 1) printPaths2(i + 1, j, n, s + "Down ");
    if (j < n - 1) printPaths2(i, j + 1, n, s + "Right ");
    if (i < n - 1 && j < n - 1) printPaths2(i + 1, j + 1, n, s + "Diagonal ");
}
//With Obstacles
void printPaths3(int i, int j, vector<vector<bool>> v, string s) {
    if (i == v[0].size() - 1 && j == v[0].size() - 1) {
        cout << s << endl;
        return;
    }
    if (!v[i][j]) return;
    if (i < v[0].size() - 1) printPaths3(i + 1, j, v, s + "Down ");
    if (j < v[0].size() - 1) printPaths3(i, j + 1, v, s + "Right ");
}
//All paths
void printPaths4(int i, int j, vector<vector<bool>>& v, string s) {
    int n = v.size();
    if (i == n - 1 && j == n - 1) {
        cout << s << endl;
        return;
    }
    if (!v[i][j]) return;
    v[i][j] = false; //visited
    if (i < n - 1) printPaths4(i + 1, j, v, s + "Down ");
    if (j < n - 1) printPaths4(i, j + 1, v, s + "Right ");
    if (i > 0) printPaths4(i - 1, j, v, s + "Up ");
    if (j > 0) printPaths4(i, j - 1, v, s + "Left ");
    v[i][j] = true; //unmarked
}
//Print Matrix and Path
void printPaths5(int i, int j, vector<vector<bool>>& v, string s, vector<vector<int>>& path, int step) {
    int n = v.size();
    if (i == n - 1 && j == n - 1) {
        path[i][j] = step;
        for (vector<int> x : path) {
            for (int y : x) cout << y << ' ';
            cout << endl;
        }
        cout << s << endl;
        return;
    }
    if (!v[i][j]) return;
    v[i][j] = false; //visited
    path[i][j] = step;
    if (i < n - 1) printPaths5(i + 1, j, v, s + "Down ", path, step + 1);
    if (j < n - 1) printPaths5(i, j + 1, v, s + "Right ", path, step + 1);
    if (i > 0) printPaths5(i - 1, j, v, s + "Up ", path, step + 1);
    if (j > 0) printPaths5(i, j - 1, v, s + "Left ", path, step + 1);
    v[i][j] = true; //unmarked
    path[i][j] = 0;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    cin >> x;
    //printPaths(0, 0, x, "");
    //cout << endl;
    //cout << noOfPaths(0, 0, x) << endl;
    //cout << endl;
    //printPaths2(0, 0, x, "");
    //cout << endl;
    vector<vector<bool>> v(x, vector<bool>(x, true));
    //v[1][0] = true; //Obstacle
    //printPaths3(0, 0, v, "");
    //cout << endl;
    //v[1][1] = false;
    vector<vector<int>> path(x, vector<int>(x, 0));
    printPaths5(0, 0, v, "", path, 0);
    cout << endl;
}