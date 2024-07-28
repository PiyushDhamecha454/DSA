#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
void bubbleSort(vector<int>& v, int r, int c) {
    if (r == 0) return;
    if (c < r) {
        if (v[c] > v[c + 1]) {
            int t = v[c];
            v[c] = v[c + 1];
            v[c + 1] = t;
        }
        bubbleSort(v, r, c + 1);
    } else bubbleSort(v, r - 1, 0);
}
void selectionSort (vector<int>& v, int r, int c, int max) {
    if (r == 0) return;
    if (c < r) {
        if (v[c] > v[max]) selectionSort(v, r, c + 1, c);
        else selectionSort(v, r, c + 1, max);
    } else {
        int t = v[r - 1];
        v[r - 1] = v[max];
        v[max] = t;
        selectionSort(v, r - 1, 0, 0);
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {5,6,3,2,1,7};
    selectionSort(v, v.size() - 1, 0, 0);
    for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
    cout << endl;    
}