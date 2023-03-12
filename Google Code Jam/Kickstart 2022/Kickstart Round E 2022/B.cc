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

    int n;
    for (int case_ = 0; case_ < T; case_++) {
        input(n);
        vector<int> ns(n);
        multiset<int> st;
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
            st.insert(ns[i]);
        }

        printf("Case #%d:", case_ + 1);
        for (auto num : ns) {
            st.erase(st.find(num));

            auto iter = st.upper_bound(num * 2);
            if (iter == st.begin()) {
                printf(" -1");
            } else {
                --iter;
                printf(" %d", *iter);
            }

            st.insert(num);
        }
        puts("");

    }

    return 0;
}

/*

^^^TEST^^^
3
3
2000 1500 1900
5
1000 600 1000 2300 1800
2
2500 1200
-----
Case #1: 1900 2000 2000
Case #2: 1800 1000 1800 1800 2300
Case #3: 1200 -1
$$$TEST$$$

*/
