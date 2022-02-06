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
llint k;
vector<int> res;

bool solve(int n, llint k, int p, int delta) {
    if (n == 0) {
        return true;
    }

    if (n == 1) {
        if (k == 0) {
            res[p] = 1 + delta;
            return true;
        }
        return false;
    }

    llint u = 1LL << min(62, (n - 2));
    int head = 1;
    while (k >= u && k != 0) {
        if (u == 0) {
            return false;
        }
        head++;
        k -= u;
        u /= 2;
    }

    res[p] = head + delta;
    p++;
    for (int i = head - 1; i >= 1; i--) {
        res[p] = i + delta;
        p++;
    }

    bool flag = solve(n - head, k, p, delta + head);
    if (flag == false) {
        return false;
    }
    return true;
}

int main() {
    int T;
    input(T);
    for (int case_ = 0; case_ < T; case_++) {
        input(n, k);
        res = vector<int>(n, -1);

        bool flag = solve(n, k - 1, 0, 0);

        if (flag == false) {
            puts("-1");
        } else {
            for (int i = 0; i < n; i++) {
                printf("%d ", res[i]);
            }
            puts("");
        }
    }
    return 0;
}

/*

^^^TEST^^^
5
1 1
1 2
3 3
6 5
3 4
----
1 
-1
2 1 3 
1 2 4 3 5 6 
3 2 1 
$$$TEST$$$

^^^TEST^^^
17
5 1
5 2
5 3
5 4
5 5
5 6
5 7
5 8
5 9
5 10
5 11
5 12
5 13
5 14
5 15
5 16
5 17
---
1 2 3 4 5
1 2 3 5 4
1 2 4 3 5
1 2 5 4 3
1 3 2 4 5
1 3 2 5 4
1 4 3 2 5
1 5 4 3 2
2 1 3 4 5
2 1 3 5 4
2 1 4 3 5
2 1 5 4 3
3 2 1 4 5
3 2 1 5 4
4 3 2 1 5
5 4 3 2 1
-1
$$$TEST$$$

*/

// -----------------------------------------

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

const int SIZE = 123456;

llint dp[SIZE];

llint dfs(int cur, int n, llint k, vector<int>& res) {
    if (cur == n) {
        return 1;
    }

    if (dp[n - cur] != -1) {
        if (dp[n - cur] < k) {
            return dp[n - cur];
        }
    }

    llint tot = 0;
    bool flag = false;
    for (int i = 1; cur + i <= n; i++) {
        tot += dfs(cur + i, n, k - tot, res);
        if (tot >= k && flag == false) {
            flag = true;
            for (int j = 0; j < i; j++) {
                res[cur + j] = cur + i - j;
            }
            break;
        }
    }

    if (flag) {
        return tot;
    } else {
        return dp[n - cur] = tot;
    }
}

void solve(int n, llint k, vector<int>& res) {
    dfs(0, n, k, res);
}

int main() {
    int T;
    input(T);

    memset(dp, -1, sizeof(dp));

    int n;
    llint k;
    while (T--) {
        input(n, k);

        vector<int> ns(n, -1);
        solve(n, k, ns);

        if (ns[0] == -1) {
            puts("-1");
        } else {
            for (auto num : ns) {
                printf("%d ", num);
            }
            puts("");
        }
    }

    return 0;
}

/*

^^^TEST^^^
5
1 1
1 2
3 3
6 5
3 4
-----
1 
-1
2 1 3 
1 2 4 3 5 6 
3 2 1 
$$$TEST$$$

*/

