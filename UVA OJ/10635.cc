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

const int SIZE = 250 * 250 + 123;

int n, p, q;

int main() {
    int T;
    input(T);
    for (int case_ = 0; case_ < T; case_++) {
        input(n, p, q);
        p++;
        q++;

        map<int, int> mp;
        vector<int> ps(p);
        for (int i = 0; i < p; i++) {
            scanf("%d", &ps[i]);
            mp[ps[i]] = i;
        }

        vector<int> qs(q);
        for (int i = 0; i < q; i++) {
            scanf("%d", &qs[i]);
            if (mp.count(qs[i])) {
                qs[i] = mp[qs[i]];
            } else {
                qs[i] = -1;
            }
        }

        vector<int> st;
        for (auto num : qs) {
            if (st.empty() || num > *st.rbegin()) {
                st.push_back(num);
                continue;
            }
            auto iter = lower_bound(st.begin(), st.end(), num);
            *iter = num;
        }
        printf("Case %d: %lu\n", case_ + 1, st.size());
    }
    return 0;
}

/*

^^^TEST^^^
2
3 6 7
1 7 5 4 8 3 9
1 4 3 5 6 2 8 9
3 6 7
1 7 5 4 8 3 9
1 4 3 5 6 2 8 9
-----
Case 1: 4
Case 2: 4
$$$TEST$$$

*/
