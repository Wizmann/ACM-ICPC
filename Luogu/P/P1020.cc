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

int solve1(const vector<int>& ns_) {
    vector<int> ns(ns_);
    reverse(ns.begin(), ns.end());

    vector<int> st;
    for (auto num : ns) {
        if (st.empty()) {
            st.push_back(num);
            continue;
        }
        auto iter = upper_bound(st.begin(), st.end(), num);
        if (iter == st.end()) {
            st.push_back(num);
        } else {
            *iter = num;
        }
    }
    return st.size();
}

int solve2(const vector<int>& ns) {
    const int n = ns.size();
    int l = 1;
    int r = n;
    while (l <= r) {
        int m = (l + r) / 2;
        set<int> st;

        for (auto num : ns) {
            auto it = st.lower_bound(num);
            if (it == st.end()) {
                st.insert(num);
            } else {
                st.erase(it);
                st.insert(num);
            }

            if ((int)st.size() > m) {
                break;
            }
        }

        if ((int)st.size() > m) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return l;
}

int main() {
    vector<int> ns;

    int x;
    while (input(x)) {
        ns.push_back(x);
    }

    print(solve1(ns));
    print(solve2(ns));

    return 0;
}

/*

^^^TEST^^^
389 207 155 300 299 170 158 65
-----
6
2
$$$TEST$$$

^^^TEST^^^
3 2 1 3 2 1
-----
4
2
$$$TEST$$$

^^^TEST^^^
1 1 1
-----
3
1
$$$TEST$$$

^^^TEST^^^
1 2 3 1
-----
2
3
$$$TEST$$$

^^^TEST^^^
10 10 1 10 1 1 1
-----
6
2
$$$TEST$$$

^^^TEST^^^
5 4 3 1 10 1
-----
5
2
$$$TEST$$$

*/
