#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
bool balancedParenthesis (string s) {
    stack<char> st;
    string y = s;
    int i = 0;
    while (i < s.size()) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
        else {
            if (st.empty()) return false;
            if (st.top() == '(' && s[i] == ')' || st.top() == '{' && s[i] == '}' || st.top() == '[' && s[i] == ']') st.pop();
            else return false;
        }
        i++;
    }
    return st.empty();
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s = "([{}()])", t = "([){]}";
    cout << balancedParenthesis(s) << '\n' << balancedParenthesis(t) << endl;
}