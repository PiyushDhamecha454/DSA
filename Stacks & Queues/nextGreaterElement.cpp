#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nextGreaterMap;
    stack<int> s;
    for (int i = nums2.size() - 1; i >= 0; i--) {
        int current = nums2[i];
        while (!s.empty() && s.top() <= current) s.pop();
        if (s.empty()) nextGreaterMap[current] = -1;
        else nextGreaterMap[current] = s.top();
        s.push(current);
    }
    vector<int> nums3;
    for (int x : nums1) nums3.push_back(nextGreaterMap[x]);
    return nums3;
}
vector<int> nextGreaterElement2(vector<int>& nums) {
    unordered_map<int, int> nextGreaterMap;
    stack<int> s;
    for (int i = nums.size() - 1; i >= 0; i--) {
        int current = nums[i];
        while (!s.empty() && s.top() <= current) s.pop();
        if (s.empty()) nextGreaterMap[current] = -1;
        else nextGreaterMap[current] = s.top();
        s.push(current);
    }
    vector<int> nums3;
    for (int x : nums) nums3.push_back(nextGreaterMap[x]);
    return nums3;
}
/*
(>__<)
    current = 2
    nextGreaterMap[2] = -1
    stack = {2}
    current = 4
    nextGreaterMap[4] = -1
    stack = {4}
    current = 3
    nextGreaterMap[3] = 4
    stack = {4, 3}
    current = 1
    nextGreaterMap[1] = 3
    stack = {4, 3}
    nums3 = {-1, 3, -1}
_____________________________________________________________________________________________________________________________________________________________
    current = 4
    nextGreaterMap[4] = -1
    stack = {4}
    current = 3
    nextGreaterMap[3] = 4
    stack = {4, 3}
    current = 2
    nextGreaterMap[2] = 3
    stack = {4, 3, 2}
    current = 1
    nextGreaterMap[1] = 2
    stack = {4, 3, 2, 1}
    nums3 = {3, -1}
*/
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums1 = {4, 1, 2}, nums2 = {1, 3, 4, 2};
    vector<int> nums3 = nextGreaterElement(nums1, nums2);
    for (int x : nums3) cout << x << ' ';
    cout << endl;
    nums2.clear();
    nums3.clear();
    nums2 = {1, 2, 3, 4, 3};
    nums3 = nextGreaterElement2(nums2);
    for (int x : nums3) cout << x << ' ';
    cout << endl;
}