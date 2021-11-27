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
int k;

int solve() {
    int n = s.size();
    vector<int> pre(n, 0);
    vector<int> ones;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'X') {
            ones.push_back(i);
            pre[i] = 1;
        }
        if (i - 1 >= 0) {
            pre[i] += pre[i - 1];
        }
    }

    if (ones.empty()) {
        return min(n, k);
    }

    int m = ones.size();
    int l = 0;
    int r = 0;
    int maxi = 0;
    while (l < m && r < m) {
        int a = ones[l];
        int b = ones[r];
        int cur = b - a + 1;
        int filled = pre[b] - (a - 1 >= 0? pre[a - 1]: 0);
        int rem = n - (b - a + 1);

        int tot = 0;
        int kk = k;
        if (cur - filled <= k) {
            tot += cur;
            kk -= (cur - filled);
            tot += min(rem, kk);
            r++;
        } else {
            l++;
        }
        maxi = max(maxi, tot);
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
XX...X.X.X.
2
-----
5
$$$TEST$$$

^^^TEST^^^
XX...
100000
-----
5
$$$TEST$$$

^^^TEST^^^
.....
100000
-----
5
$$$TEST$$$

^^^TEST^^^
.X..X
1
-----
2
$$$TEST$$$

^^^TEST^^^
.X..X
3
-----
5
$$$TEST$$$

^^^TEST^^^
.X..X
2
-----
4
$$$TEST$$$

^^^TEST^^^
XXXX
200000
-----
4
$$$TEST$$$

*/
