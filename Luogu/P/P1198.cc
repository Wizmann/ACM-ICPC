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
    int q;
    llint mod;
    input(q, mod);

    vector<llint> ns;
    deque<llint> dq;

    char cmd[5];
    int v;
    llint pre = 0;

    while (q--) {
        scanf("%s%d", cmd, &v);
        if (cmd[0] == 'Q') {
            int idx = ns.size() - v;
            auto iter = lower_bound(dq.begin(), dq.end(), idx);
            print(ns[*iter]);
            pre = ns[*iter];
        } else if (cmd[0] == 'A') {
            v = (1LL * v + pre) % mod;
            ns.push_back(v);
            int idx = ns.size() - 1;
            while (!dq.empty() && ns[*dq.rbegin()] <= v) {
                dq.pop_back();
            }
            dq.push_back(idx);
        } else {
            assert(false);
        }
    }

    return 0;
}

/*

^^^TEST^^^
5 100
A 96
Q 1
A 97
Q 1
Q 2
-----
96
93
96
$$$TEST$$$

*/
