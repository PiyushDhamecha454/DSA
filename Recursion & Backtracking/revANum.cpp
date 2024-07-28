// g++ sumOfDigits.cpp
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
int sum = 0;
void revANum (int n) {
    if (n < 10) {
        cout << n << endl;
        return;
    }
    cout << n % 10 << endl;
    revANum(n / 10);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    revANum(1432);
}