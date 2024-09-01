#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
bool isOperator(char c) {
    return (!isalpha(c) && !isdigit(c));
}
int getPriority(char c) {
    if (c == '-' || c == '+') return 1;
    else if (c == '*' || c == '/') return 2;
    else if (c == '^') return 3;
    return 0;
}
string inPost (string infix) {
    infix = '(' + infix + ')';
    int l = infix.size();
    stack<char> st;
    string postfix;
    for (int i = 0; i < l; i++) {
        if (isalpha(infix[i]) || isdigit(infix[i])) postfix += infix[i];
        else if (infix[i] == '(') st.push(infix[i]);
        else if (infix[i] == ')') {
            while (st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // "x + y * z / w + u"
        }
        else {
            if (isOperator(st.top())) {
                if (infix[i] == '^') {
                    while (getPriority(infix[i]) <= getPriority(st.top())) {
                        postfix += st.top();
                        st.pop();
                    }
                }
                else {
                    while (getPriority(infix[i]) < getPriority(st.top())) {
                        postfix += st.top();
                        st.pop();
                    }
                }
                st.push(infix[i]);
            }
        }
    }
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}
string inPre (string infix) {
    int l = infix.size();
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < l; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }
    stack<char> st;
    string prefix;
    for (int i = 0; i < l; i++) {
        if (isalnum(infix[i])) prefix += infix[i];
        else if (infix[i] == ')') st.push(infix[i]);
        else if (infix[i] == '(') {
            while (!st.empty() && st.top() != ')') {
                prefix += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (isOperator(infix[i])) {
            while (!st.empty() && getPriority(st.top()) >= getPriority(infix[i])) {
                prefix += st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
    }
    while (!st.empty()) {
        prefix += st.top();
        st.pop();
    }
    reverse (prefix.begin(), prefix.end());
    return prefix;
}
string prePost(string prefix) {
    stack<string> st;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isalpha(c) || isdigit(c)) {
            string operand(1, c);
            st.push(operand);
        }
        else {
            string operand1 = st.top();
            st.pop();
            string operand2 = st.top();
            st.pop();
            string postfix = operand1 + operand2 + c;
            st.push(postfix);
        }
    }
    return st.top();
}
string preIn (string prefix) {
    stack<string> st;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isalpha(c) || isdigit(c)) st.push(string(1, c));
        else {
            string operand1 = st.top();
            st.pop();
            string operand2 = st.top();
            st.pop();
            string infix = "(" + operand1 + c + operand2 + ")";
            st.push(infix);
        }
    }
    return st.top();
}
string postIn (string postfix) {
    stack<string> st;
    for (char c : postfix) {
        if (isalpha(c) || isdigit(c)) st.push(string(1, c));
        else {
            string operand2 = st.top();
            st.pop();
            string operand1 = st.top();
            st.pop();
            string infix = "(" + operand1 + c + operand2 + ")";
            st.push(infix);
        }
    }
    return st.top();
}
string postPre(string postfix) {
    stack<string> st;
    for (char c : postfix) {
        if (isalpha(c) || isdigit(c)) st.push(string(1, c));
        else {
            string operand2 = st.top();
            st.pop();
            string operand1 = st.top();
            st.pop();
            string prefix = c + operand1 + operand2;
            st.push(prefix);
        }
    }
    return st.top();
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s = "x+y*z/w+u";
    cout << inPre(s) << endl;
}