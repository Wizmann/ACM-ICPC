#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

constexpr int log2(int x) {
    return (x > 1) ? (1 + log2(x >> 1)) : 0;
}

const int INF = 0x3f3f3f3f;

class SegTree {
public:
    const int UNKNOWN = -INF;

    SegTree(const vector<int>& ns) {
        assert(log2(2) == 1);
        assert(log2(1) == 0);

        n = ns.size();
        N = 1 << (log2(n) + 1);
        assert(N > n);

        rangeL = vector<int>(N * 2, -1);
        rangeR = vector<int>(N * 2, -1);

        values = vector<int>(N * 2, 1);

        for (int i = 0; i <= n; i++) {
            rangeL[N + i] = rangeR[N + i] = i;
        }

        for (int i = 0; i <= n; i++) {
            values[N + i] = ns[i];
        }

        for (int i = N - 1; i > 0; i--) {
            rangeL[i] = rangeL[left(i)];
            rangeR[i] = rangeR[right(i)];
            pushUp(i);
        }
    }

    void attack(int x) {
        if (query(x, x) == 0) {
            return;
        }
        do_update(x, -1);
    }

    void repair(int x) {
        if (query(x, x) == 1) {
            return;
        }
        do_update(x, 1);
    }

    int query(int l, int r) {
        l += N - 1;
        r += N + 1;

        int res = 0;
        while (!isNeighbour(l, r)) {
            if (isLeft(l)) {
                res += values[sibling(l)];
            }
            if (isRight(r)) {
                res += values[sibling(r)];
            }

            l = parent(l);
            r = parent(r);
        }
        return res;
    }

private:
    void pushUp(int x) {
        assert(x < N);
        values[x] = values[left(x)] + values[right(x)];
    }

    void do_update(int cur, int delta) {
        cur += N;

        while (cur) {
            values[cur] += delta;
            cur = parent(cur);
        }
    }
private:
    int left(int x) { return x * 2; }
    bool isLeft(int x) { return x % 2 == 0; }
    int right(int x) { return x * 2 + 1; }
    int isRight(int x) { return x % 2 == 1; }
    int isNeighbour(int x, int y) { return abs(x - y) == 1; }
    int parent(int x) { return x / 2; }
    int sibling(int x) { return x ^ 1; }
    bool isLeaf(int x) { return x > N; }

    vector<int> rangeL;
    vector<int> rangeR;

    vector<int> values;

    int n;
    int N;
};

int main() {
    int n, m;
    while (input(n >> m)) {
        vector<int> ns(n + 1, 1);

        SegTree st(ns);

        int a;
        char cmd[5];
        vector<int> history;
        while (m--) {
            scanf("%s", cmd);
            if (cmd[0] == 'D') {
                scanf("%d", &a);
                history.push_back(a);
                st.attack(a);
            } else if (cmd[0] == 'Q') {
                scanf("%d", &a);
                int res = 0;

                if (st.query(a, a) == 0) {
                    printf("0\n");
                    continue;
                }

                {
                    int l = 0;
                    int r = a;
                    while (l <= r) {
                        int m = (l + r) >> 1;
                        int q = st.query(a - m + 1, a);
                        assert(q <= m);
                        if (q == m) {
                            l = m + 1;
                        } else {
                            r = m - 1;
                        }
                    }
                    res += r;
                }
                {
                    int l = 0;
                    int r = n - a + 1;
                    while (l <= r) {
                        int m = (l + r) >> 1;
                        int q = st.query(a, a + m - 1);
                        assert(q <= m);
                        if (q == m) {
                            l = m + 1;
                        } else {
                            r = m - 1;
                        }
                    }
                    res += r;
                }
                printf("%d\n", res - 1);
            } else {
                st.repair(*history.rbegin());
                history.pop_back();
            }
        }
    }
    return 0;
}
