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

struct Monitor {
    int t, pos;

    bool operator < (const Monitor& other) const {
        if (t != other.t) {
            return t < other.t;
        } else {
            return pos < other.pos;
        }
    }
};

int calc(const Monitor& m0, const Monitor& m1) {
    return abs(m0.pos - m1.pos) / abs(m0.t - m1.t);
}

int main() {
    int n, m;
    input(n, m);

    vector<Monitor> monitors;
    set<Monitor> st;
    for (int i = 0; i < n; i++) {
        int t, x;
        scanf("%d%d", &x, &t);
        Monitor m{t, x};
        monitors.emplace_back(m);
        st.insert(m);
    }

    multiset<int> results;
    for (auto iter = st.begin(); iter != st.end(); /* pass */) {
        auto prev = iter;
        ++iter;
        int u = calc(*prev, *iter);
        results.insert(u);
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--;

        vector<int> added;
        vector<int> removed;

        auto m0 = monitors[u];
        auto m1 = Monitor{v, m0.pos};

        {
            auto iter1 = st.find(m0);
            if (iter1 != st.begin()) {
                auto iter0 = iter1;
                iter0--;
                int u = calc(*iter0, *iter1);
                removed.push_back(u);
                results.erase(results.find(u));
            }
            if (iter1 != st.end()) {
                auto iter2 = iter1;
                ++iter2;
                int u = calc(*iter1, *iter2);
                removed.push_back(u);
                results.erase(results.find(u));
            }
            if (iter1 != st.begin() && iter1 != st.end()) {
                auto iter0 = iter1;
                iter0--;
                auto iter2 = iter1;
                ++iter2;
                int u = calc(*iter0, *iter2);
                added.push_back(u);
                results.insert(u);
            }
        }

        st.erase(st.find(m0));
        st.insert(m1);

        {
            auto iter1 = st.find(m1);
            if (iter1 != st.begin()) {
                auto iter0 = iter1;
                iter0--;
                int u = calc(*iter0, m1);
                added.push_back(u);
                results.insert(u);
            }
            if (iter1 != st.end()) {
                auto iter2 = iter1;
                iter2++;
                int u = calc(m1, *iter2);
                added.push_back(u);
                results.insert(u);
            }
            if (iter1 != st.begin() && iter1 != st.end()) {
                auto iter0 = iter1;
                iter0--;
                auto iter2 = iter1;
                ++iter2;
                int u = calc(*iter0, *iter2);
                removed.push_back(u);
                results.erase(results.find(u));
            }
        }

        print(*results.rbegin());

        st.erase(st.find(m1));
        st.insert(m0);

        for (auto u : removed) {
            results.insert(u);
        }
        for (auto u : added) {
            results.erase(results.find(u));
        }
    }

    return 0;
}


/*
^^^^^TEST^^^^
5 3
10 3
-10 1
0 5
-5 0
10 7
1 2
2 2
3 100
------------
20
20
10
$$$$$TEST$$$$
*/
