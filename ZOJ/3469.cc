#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1111;
const int INF = 0x3f3f3f3f;

struct Node {
    int pos, b;

    bool operator < (const Node& other) const {
        return pos < other.pos;
    }
};

int n, v, x;
vector<Node> nodes;
int dp[SIZE][SIZE];
vector<int> sum;

int do_solve(int st, int l, int r) {
    int& u = dp[l][r];
    if (u != -1) {
        return u;
    }

    if (l == r) {
        return 0;
    }

    int res = INF;

    if (l < r && r - 1 >= st) {
        int end = r;
        int cur1 = do_solve(st, l, r - 1);
        cur1 += (sum[l - 1] + sum[n] - sum[r - 1]) * abs(nodes[r - 1].pos - nodes[end].pos);
        res = min(res, cur1);

        int cur2 = do_solve(st, r - 1, l);
        cur2 += (sum[l - 1] + sum[n] - sum[r - 1]) * abs(nodes[l].pos - nodes[end].pos);
        res = min(res, cur2);
    }

    if (l > r && r + 1 <= st) {
        int end = r;
        swap(l, r);

        int cur1 = do_solve(st, r, l + 1);
        cur1 += (sum[l] + sum[n] - sum[r]) * abs(nodes[l + 1].pos - nodes[end].pos);
        res = min(res, cur1);

        int cur2 = do_solve(st, l + 1, r);
        cur2 += (sum[l] + sum[n] - sum[r]) * abs(nodes[r].pos - nodes[end].pos);
        res = min(res, cur2);
    }

    return u = res;
}

int solve() {
    memset(dp, -1, sizeof(dp));
    int st = -1;
    sum = vector<int>(n + 1, 0);
    for (int i = 0; i <= n; i++) {
        if (i - 1 >= 0) {
            sum[i] += sum[i - 1];
        }
        sum[i] += nodes[i].b;
    }
    for (int i = 1; i <= n; i++) {
        if (nodes[i].pos == x) {
            st = i;
            break;
        }
    }

    return min(do_solve(st, 1, n), do_solve(st, n, 1));
}

int main() {
    freopen("input.txt", "r", stdin);
    while (input(n >> v >> x)) {
        n++;
        nodes = vector<Node>(n + 1);
        nodes[0] = {0, 0};
        nodes[1] = {x, 0};

        int pos, b;
        for (int i = 2; i <= n; i++) {
            scanf("%d%d", &pos, &b);
            nodes[i] = {pos, b};
        }

        sort(nodes.begin() + 1, nodes.end());

        printf("%d\n", solve() * v);
    }
    return 0;
}
