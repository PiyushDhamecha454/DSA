#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
int x = 0;
int numberOfSteps(int n) {
    if (n == 0) return x;
    else if (n % 2) {
        x++;
        return numberOfSteps(n - 1);
    }
    x++;
    return numberOfSteps(n / 2);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << numberOfSteps(14) << endl;
    x = 0;
    cout << numberOfSteps(8) << endl;
    x = 0;
    cout << numberOfSteps(123) << endl;
}