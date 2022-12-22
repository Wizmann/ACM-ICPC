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

    for (int case_ = 0; case_ < T; case_++) {
        int n;
        input(n);

        vector<int> ns(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        multiset<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(ns[i]);
        }

        int ans = -INF;
        for (int i = 0; i < n; i++) {
            auto iter = st.find(ns[i]);
            st.erase(iter);

            if (st.empty()) {
                break;
            }
            int mini = *st.begin();

            ans = max(ans, ns[i] - mini);
        }

        printf("%d\n", ans);
    }

    return 0;
}

/*

^^^TEST^^^
3
2
100
20
4
4
3
2
1
4
1
2
3
4
-----
80
3
-1
$$$TEST$$$

*/
