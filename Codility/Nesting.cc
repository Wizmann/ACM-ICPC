// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <stack>

int solution(string &S) {
    stack<char> st;
    for (auto c: S) {
        if (st.empty() || c == '(') {
            st.push(c);
        } else {
            if (st.top() != '(') {
                break;
            } else {
                st.pop();
            }
        }
    }
    return st.empty();
}
