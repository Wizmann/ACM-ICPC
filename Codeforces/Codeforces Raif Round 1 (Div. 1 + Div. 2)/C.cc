#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

int main() {
    int T;
    input(T);

    string s;

    while (T--) {
        input(s);
        int n = s.size();

        stack<char> st;
        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            if (st.empty()) {
                st.push(c);
                continue;
            }

            if (c == 'A' && st.top() == 'B') {
                st.pop();
            } else {
                st.push(c);
            }
        }

        int res = st.size();

        while (st.size() >= 2) {
            char a = st.top();
            st.pop();
            char b = st.top();
            st.pop();
            if (a == 'B' && b == 'B') {
                res -= 2;
            }
        }

        print(res);
    }

    return 0;
}

/*

^^^TEST^^^
3
AAA
BABA
AABBBABBBB
-----
3
2
0
$$$TEST$$$

*/
