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

struct Operation {
    int type;
    int value;
};

bool checkStack(const vector<Operation>& ops) {
    stack<int> st;
    for (const auto& op : ops) {
        if (op.type == 1) {
            st.push(op.value);
        } else {
            if (st.empty() || st.top() != op.value) {
                return false;
            }
            st.pop();
        }
    }
    return true;
}

bool checkQueue(const vector<Operation>& ops) {
    queue<int> st;
    for (const auto& op : ops) {
        if (op.type == 1) {
            st.push(op.value);
        } else {
            if (st.empty() || st.front() != op.value) {
                return false;
            }
            st.pop();
        }
    }
    return true;
}

bool checkPQ(const vector<Operation>& ops) {
    priority_queue<int> st;
    for (const auto& op : ops) {
        if (op.type == 1) {
            st.push(op.value);
        } else {
            if (st.empty() || st.top() != op.value) {
                return false;
            }
            st.pop();
        }
    }
    return true;
}

int main() {
    int n;
    while (input(n)) {
        vector<Operation> ops(n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &ops[i].type, &ops[i].value);
        }

        bool is_stack = checkStack(ops);
        bool is_queue = checkQueue(ops);
        bool is_pq    = checkPQ(ops);

        if (is_stack + is_queue + is_pq == 1) {
            if (is_stack) { puts("stack"); }
            if (is_queue) { puts("queue"); }
            if (is_pq)    { puts("priority queue"); }
        } else if (is_stack + is_queue + is_pq > 1) {
            puts("not sure");
        } else {
            puts("impossible");
        }
    }

    return 0;
}

/*

^^^TEST^^^
6
1 1
1 2
1 3
2 1
2 2
2 3
6
1 1
1 2
1 3
2 3
2 2
2 1
2
1 1
2 2
4
1 2
1 1
2 1
2 2
7
1 2
1 5
1 1
1 3
2 5
1 4
2 4
-----
queue
not sure
impossible
stack
priority queue
$$$TEST$$$

*/
