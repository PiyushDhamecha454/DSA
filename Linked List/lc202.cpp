#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
int sumOfSquareOfDigits (int n) {
    int sum = 0;
    while (n > 0) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}
bool isHappy(int n) {
    unordered_set<int> seen;
    while (true) {
        int a = sumOfSquareOfDigits(n);
        if (a == 1) return true;
        if (seen.find(a) != seen.end()) return false;
        seen.insert(a);
        n = a;
    }
    return true;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        cout << (bool) isHappy(n) << endl;
    }
}