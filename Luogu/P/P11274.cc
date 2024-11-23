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
#include <unordered_map>

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

const int N = 3003;

int n;
vector<int> nums;
vector<int> bs;

vector<llint> dp;

int get_id(int a, int b, bool flag) {
    assert(a <= n);
    assert(b <= n);
    return ((1 + a) * a / 2 + b) * 2 + flag;
}

llint dfs(int cur, int skip, bool flag) {
    if (cur == n + 1) {
        if (skip == 0) {
            return 0;
        }
        return -INFLL;
    }
    llint maxi = -INFLL;

    if (skip > cur) {
        return -INFLL;
    }

    const int h = get_id(cur, skip, flag);
    assert(h < (int)dp.size());

    if (dp[h] != -INFLL - 1) {
        return dp[h];
    }

    maxi = max(maxi, dfs(cur + 1, skip, flag));

    if (flag) {
        if (bs[cur] <= skip) {
            maxi = max(maxi, dfs(cur + 1, skip - bs[cur], true) + nums[cur]);
        }
    } else {
        if (bs[cur] >= skip) {
            maxi = max(maxi, dfs(cur + 1, 1, false));
            maxi = max(maxi, dfs(cur + 1, 0, true) + nums[cur]);
        } else {
            maxi = max(maxi, dfs(cur + 1, skip - bs[cur] + 1, false));
            maxi = max(maxi, dfs(cur + 1, skip - bs[cur], true) + nums[cur]);
        }
    }

    // print(cur, skip, flag, maxi);
    return dp[h] = maxi;
}


bool dfs2(int cur, int skip, bool flag, llint tot, vector<int>& path) {
    if (cur == n + 1) {
        return skip == 0 && tot == 0;
    }

    if (skip > cur) {
        return false;
    }

    const int h = get_id(cur, skip, flag);
    if (dp[h] != tot) {
        return false;
    }

    if (dfs2(cur + 1, skip, flag, tot, path)) {
        return true;
    }

    path.push_back(cur);
    llint tot2 = tot - nums[cur];
    if (flag) {
        if (bs[cur] <= skip) {
            if (dfs2(cur + 1, skip - bs[cur], true, tot2, path)) {
                return true;
            }
        }
    } else {
        if (bs[cur] >= skip) {
            if (dfs2(cur + 1, 1, false, tot, path)) {
                return true;
            }

            if (dfs2(cur + 1, 0, true, tot2, path)) {
                return true;
            }
        } else {
            if (dfs2(cur + 1, skip - bs[cur] + 1, false, tot, path)) {
                return true;
            }
            if (dfs2(cur + 1, skip - bs[cur], true, tot2, path)) {
                return true;
            }
        }
    }
    path.pop_back();
    return false;
}

int main() {
    scanf("%d", &n);

    nums.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
    }

    bs.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &bs[i]);
    }

    dp = vector<llint>((n + 2) * (n + 1), -INFLL - 1);

    llint maxi = dfs(1, 0, false);

    vector<int> path;
    path.reserve(N);
    dfs2(1, 0, false, maxi, path);

    printf("%d\n", int(path.size()));
    for (auto num : path) {
        printf("%d ", num);
    }
    puts("");
    printf("%lld\n", maxi);

    return 0;
}

/*

^^^TEST^^^
6
1 1 4 5 1 4
1 0 0 2 1 1
-----
4
1 2 3 4
9
$$$TEST$$$

^^^TEST^^^
1
1
1
-----
1
1
1
$$$TEST$$$

^^^^TEST^^^^
13
-1 1 4 -5 -1 -4 1 9 -1 9 -8 -1 0
1 0 2 1 3 0 0 2 0 0 2 0 1
------------
5
1 2 7 8 10 
19
$$$$$$$TEST$$$$

^^^^TEST^^^^
6
1 1 4 5 1 4
1 1 1 3 0 1
------------
2
4 5
6
$$$$$$$TEST$$$$

^^^^TEST^^^^
3
-1 -2 -3
0 0 0
------------
0

0
$$$$$$$TEST$$$$

*/
