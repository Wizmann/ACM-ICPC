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

string s;
llint k;

llint solve() {
    int n = s.size();
    vector<int> ys;
    vector<int> ones(n, 0);
    vector<llint> poses(n, 0);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'Y') {
            ones[i] = 1;
            poses[i] = i;
            ys.push_back(i);
        }
        if (i - 1 >= 0) {
            ones[i] += ones[i - 1];
            poses[i] += poses[i - 1];
        }
    }

    int m = ys.size();
    int maxi = 0;
    int l = 0;
    int r = 0;

    while (l < m && r < m) {
        int a = ys[l];
        int b = ys[r];
        int m = ys[(l + r) / 2];

        llint tot = 0;
        // left 
        {
            int u = ones[m] - (a - 1 >= 0? ones[a - 1]: 0);
            llint v = poses[m] - (a - 1 >= 0? poses[a - 1]: 0);

            tot += 1LL * m * u - v - 1LL * (u - 1) * u / 2;
        }
        // right
        {
            int u = ones[b] - ones[m];
            llint v = poses[b] - poses[m];

            tot += v - 1LL * (m + 1) * u - 1LL * (u - 1) * u / 2;
        }

        if (tot > k) {
            l++;
        } else {
            maxi = max(maxi, r - l + 1);
            r++;
        }
    }
    return maxi;
}

int main() {
    input(s);
    input(k);

    print(solve());

    return 0;
}

/*

^^^TEST^^^
Y.Y
1
-----
2
$$$TEST$$$

^^^TEST^^^
Y.Y..YY
5
-----
4
$$$TEST$$$

^^^TEST^^^
YY
2
-----
2
$$$TEST$$$

^^^TEST^^^
YY...Y.Y.Y.
2
-----
3
$$$TEST$$$

^^^TEST^^^
YY...Y.Y.Y.
100000000000
-----
5
$$$TEST$$$

^^^TEST^^^
.....Y.....
100000000000
-----
1
$$$TEST$$$

^^^TEST^^^
YYYY....YYY
3
-----
4
$$$TEST$$$

*/
