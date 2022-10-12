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

int n;
llint a;
vector<llint> ns;

int main() {
    string s;

    input(a);
    input(s);

    n = s.size();
    ns = vector<llint>(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        ns[i] = s[i - 1] - '0';
        ns[i] += ns[i - 1];
    }

    map<llint, int> mp;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            llint r = ns[j] - ns[i - 1];
            mp[r] += 1;
        }
    }

    llint res = 0;

    for (const auto& p : mp) {
        llint cur = p.first;
        int cnt1 = p.second;

        if (cur == 0 && a == 0) {
            res += 1LL * cnt1 * n * (n + 1) / 2;
            continue;
        }

        if (cur == 0 && a != 0) {
            continue;
        }

        if (a % cur != 0) {
            continue;
        }

        llint nxt = a / cur;
        int cnt2 = mp[nxt];
        // print(cur, nxt, cnt1, cnt2);

        res += 1LL * cnt1 * cnt2;
    }
    print(res);
    return 0;
}



/*

^^^TEST^^^
10
12345
-----
6
$$$TEST$$$

^^^TEST^^^
16
439873893693495623498263984765
-----
40
$$$TEST$$$

^^^TEST^^^
0
1230
-----
19
$$$TEST$$$

*/
