#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int> main, helper;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        main.push(a);
    }
    for (int i = 0; i < n; i++) {
        helper.push(main.top());
        main.pop();
    }
    for (int i = 0; i < n; i++) {
        cout << helper.top() << ' ';
        helper.pop();
    }
    cout << endl;
}