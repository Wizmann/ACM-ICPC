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

const int MAXN = 512345;
const int LOG_MAXN = 22;

int rmq[LOG_MAXN][MAXN];

int main() {
    int n, m;
    input(n, m);

    vector<int> nxt(MAXN, -1);

    int a, b;
    
    memset(rmq, 0, sizeof(rmq));

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        rmq[0][a] = max(rmq[0][a], b);
    }

    for (int i = 1; i < MAXN; i++) {
        rmq[0][i] = max(rmq[0][i], rmq[0][i - 1]);
    }

    for (int i = 0; i + 1 < LOG_MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            int nxt1 = rmq[i][j];
            assert(nxt1 < MAXN);
            int nxt2 = rmq[i][nxt1];
            rmq[i + 1][j] = max(nxt1, nxt2);
        }
    }

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        int step = 0;
        for (int i = LOG_MAXN - 1; i >= 0; i--) {
            if (rmq[i][a] < b) {
                a = rmq[i][a];
                step += 1 << i;
            }
        }
        a = rmq[0][a];
        if (a < b) {
            step = -1;
        } else {
            step += 1;
        }
        printf("%d\n", step);
    }

    return 0;
}

/*

^^^TEST^^^
2 3
1 3
2 4
1 3
1 4
3 4
-----
1
2
1
$$$TEST$$$

^^^TEST^^^
3 4
1 3
1 3
4 5
1 2
1 3
1 4
1 5
-----
1
1
-1
-1
$$$TEST$$$

*/
