#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
int getMax(vector<int>& heights, stack<int>& s, int m, int i) {
    int area, popped = s.top();
    s.pop();
    if (s.empty()) area = heights[popped] * i;
    else area = heights[popped] * (i - 1 - s.top());
    return max(area, m);
}
int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int m = 0;
    s.push(0);
    for (int i = 1; i < heights.size(); i++) {
        while (!s.empty() && heights[i] < heights[s.top()]) m = getMax(heights, s, m, i);
        s.push(i);
    }
    int i = heights.size();
    while (!s.empty()) m = getMax(heights, s, m, i);
    return m;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(heights) << endl;
}