// g++ sumOfDigits.cpp
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
int sumOfDigits (int n) {
    if (n < 10) return n;
    return sumOfDigits(n / 10) + (n % 10);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << sumOfDigits(1034) << endl;
}