#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
class MinStack {
    stack<int> mainStack;
    stack<int> minStack;
    public:
        // Push element x onto the stack.
        void push(int x) {
            mainStack.push(x);
            if (minStack.empty() || x <= minStack.top()) minStack.push(x);
        }
        // Removes the element on the top of the stack.
        void pop() {
            if (mainStack.empty()) return;
            if (mainStack.top() == minStack.top()) minStack.pop();
            mainStack.pop();
        }
        // Get the top element.
        int top() {
            if (mainStack.empty()) return INT_MIN; // Handle empty stack case
            return mainStack.top();
        }
        // Retrieve the minimum element in the stack.
        int getMin() {
            if (minStack.empty()) return INT_MIN; // Handle empty stack case
            return minStack.top();
        }
};