#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
vector<int> dailyTemperatures(vector<int>& nums) {
    int l = nums.size();
    vector<int> result(l, 0);
    stack<int> st;
    for (int i = 0; i < nums.size(); i++) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            result[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    return result;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums = {30, 38, 30, 36, 35, 40, 28};
    vector<int> n = dailyTemperatures(nums);
    for (int x : n) cout << x << ' ';
    cout << endl;
}