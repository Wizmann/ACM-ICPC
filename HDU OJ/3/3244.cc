#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int INF = 0x3f3f3f3f;

typedef long long llint;

struct Node {
    int x, y, s1, p1, s2, p2;
};

llint do_count(const vector<Node>& nodes, int people, int money) {
    const int n = nodes.size();

    llint tot = 0;

    for (int i = 0; i < n; i++) {
        llint need = 1LL * people * nodes[i].x;
        llint have = nodes[i].y;

        if (have >= need) {
            continue;
        }

        llint delta = need - have;

        llint mini = INF;
        for (llint j = 0; /* pass */ ; j++) {
            llint c1 = j;
            llint t1 = c1 * nodes[i].s1;
            if (t1 - (nodes[i].s1 - 1) > delta) {
                break;
            }
            llint c2 = (delta - t1 + nodes[i].s2 - 1) / nodes[i].s2;
            c2 = max(0LL, c2);
            // print(c1 << ' ' << c2 << ' ' << c1 * nodes[i].p1 + c2 * nodes[i].p2 << ' ' << mini);
            assert(t1 + c2 * nodes[i].s2 >= delta);
            mini = min(mini, c1 * nodes[i].p1 + c2 * nodes[i].p2);
        }

        assert(mini < INF);

        tot += mini;

        if (tot > money) {
            return INF;
        }
    }
    return tot;
}

int main() {
    int n, money;
    while (scanf("%d%d", &n, &money) != EOF && n + money) {
        vector<Node> nodes(n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d%d%d%d", 
                    &nodes[i].x,
                    &nodes[i].y,
                    &nodes[i].s1,
                    &nodes[i].p1,
                    &nodes[i].s2,
                    &nodes[i].p2);
        }

        int l = 0;
        int r = 100000;
        while (l <= r) {
            int m = (1LL * l + r) / 2;
            if (do_count(nodes, m, money) > money) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        printf("%d\n", r);
    }
    return 0;
}
