// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <cassert>
#include <stack>

using namespace std;

char get_left_bracket(char c) {
    switch (c) {
        case ')':
            return '(';
        case ']':
            return '[';
        case '}':
            return '{';
    }
    assert(false);
}

int solution(string &S) {
    stack<char> st;
    for (auto c: S) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            char cc = get_left_bracket(c);
            if (st.empty() || st.top() != cc) {
                return 0;
            }
            st.pop();
        }
    }
    if (st.empty()) {
        return 1;
    } else {
        return 0;
    }
}
