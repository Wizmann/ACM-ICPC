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

set<pair<llint, llint> > st;

int main() {
    int T;
    input(T);

    for (int case_ = 0; case_ < T; case_++) {
        st.clear();
        int n, m;
        input(n, m);

        llint a, b;
        for (int i = 0; i < n; i++) {
            scanf("%lld%lld", &a, &b);
            st.insert({a, b});
        }

        vector<llint> ans;

        for (int i = 0; i < m; i++) {
            scanf("%lld", &a);

            auto iter = st.lower_bound({a, a});
            int d = INF;
            llint v = 0;
            if (iter != st.end() && iter->first <= a && iter->second >= a) {
                auto p = *iter;
                ans.push_back(a);
                st.erase(iter);
                if (p.first <= a - 1) {
                    st.insert({p.first, a - 1});
                }
                if (p.second >= a + 1) {
                    st.insert({a + 1, p.second});
                }
                d = 0;
            } else {
                d = 1;
                v = iter->first;
            }

            if (d != 0 && iter != st.begin()) {
                auto jter = iter;
                --jter;
                if (jter->first <= a && jter->second >= a) {
                    auto p = *jter;
                    ans.push_back(a);
                    st.erase(jter);
                    if (p.first <= a - 1) {
                        st.insert({p.first, a - 1});
                    }
                    if (p.second >= a + 1) {
                        st.insert({a + 1, p.second});
                    }
                    d = 0;
                } else {
                    llint u = jter->second;
                    if (abs(u - a) <= abs(v - a)) {
                        v = u;
                        d = -1;
                    }
                }
            }

            assert(d != INF);

            if (d == 1) {
                auto p = *iter;
                ans.push_back(p.first);
                p.first++;
                st.erase(iter);
                if (p.first <= p.second) {
                    st.insert(p);
                }
            } else if (d == -1) {
                --iter;
                auto p = *iter;
                ans.push_back(p.second);
                p.second--;
                st.erase(iter);
                if (p.first <= p.second) {
                    st.insert(p);
                }
            }
        }

        printf("Case #%d:", case_ + 1);

        for (auto num : ans) {
            printf(" %lld", num);
        }
        puts("");
    }

    return 0;
}

/*

^^^TEST^^^
2
5 4
1 2
6 7
9 12
24 24
41 50
14 24 24 4
1 1
42 42
24
-----
Case #1: 12 24 11 2
Case #2: 42
$$$TEST$$$

^^^TEST^^^
2
2 1
1 2
100 1000
99
2 1
0 0
100 1000
50
-----
Case #1: 100
Case #2: 0
$$$TEST$$$

*/
