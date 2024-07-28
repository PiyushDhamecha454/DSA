#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
void fun1(int r, int c) {
    if (r == 0) return;
    if (c < r) {
        cout << '*';
        fun1(r, c + 1);
    } else {
        cout << endl;
        fun1(r - 1, 0);
    }
}
void fun2(int r, int c) {
    if (r == 0) return;
    if (c < r) {
        fun2(r, c + 1);
        cout << '*';
    } else {
        fun2(r - 1, 0);
        cout << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fun1(4, 0);
    cout << endl;
    fun2(4, 0);
}

/*

1:
****
***
**
*

2:
*
**
***
****

*/