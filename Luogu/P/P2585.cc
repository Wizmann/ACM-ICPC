#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
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

const int N = 512345;

struct TreeNode {
    int l, r;
};

vector<TreeNode> nodes(N);
int dp[N][3];

class CmpMax {
public:
    static const int c_Init = -INF;
    int operator() (int a, int b) {
        return max(a, b);
    }
};

class CmpMin {
public:
    static const int c_Init = INF;
    int operator() (int a, int b) {
        return min(a, b);
    }
};

int parse(const string& s, int& ptr, int& idx) {
    int cur = idx;
    char c = s[ptr];
    idx++;

    ptr++;
    nodes[cur] = {-1, -1};

    if (c == '0') {
        // pass
    } else if (c == '1') {
        nodes[cur].l = parse(s, ptr, idx);
    } else {
        nodes[cur].l = parse(s, ptr, idx);
        nodes[cur].r = parse(s, ptr, idx);
    }

    return cur;
}

template<typename Tcmp>
int dfs(int cur, int curcolor) {
    if (dp[cur][curcolor] != -1) {
        return dp[cur][curcolor];
    }
    Tcmp cmp = Tcmp();
    int res = Tcmp::c_Init;
    if (nodes[cur].l + nodes[cur].r == -2) {
        res = curcolor == 0? 1: 0;
    } else {
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 2; j++) {
                if (i == curcolor || j == curcolor || i == j) {
                    continue;
                }
                int tot = curcolor == 0? 1: 0;
                if (nodes[cur].l != -1) {
                    tot += dfs<Tcmp>(nodes[cur].l, i);
                }
                if (nodes[cur].r != -1) {
                    tot += dfs<Tcmp>(nodes[cur].r, j);
                }
                res = cmp(res, tot);
            }
        }
    }

    // print(cur, curcolor, res);
    return dp[cur][curcolor] = res;
}

int main() {
    string s;
    input(s);

    int ptr = 0;
    int idx = 0;

    int root = parse(s, ptr, idx);
    assert(root == 0);

    int maxi = -INF;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < 3; i++) {
        maxi = max(maxi, dfs<CmpMax>(0, i));
    }

    // print("---");

    int mini = INF;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < 3; i++) {
        mini = min(mini, dfs<CmpMin>(0, i));
    }

    print(maxi, mini);

    return 0;
}

/*
^^^TEST^^^
0
---
1 0
$$$TEST$$$

^^^TEST^^^
200
---
1 1
$$$TEST$$$

^^^TEST^^^
2100
---
2 1
$$$TEST$$$

^^^TEST^^^
1122002010
---
5 2
$$$TEST$$$
*/
