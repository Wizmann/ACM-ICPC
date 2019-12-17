#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int INF = 0x3f3f3f3f;

constexpr int log2(int x) {
    return (x > 1) ? (1 + log2(x >> 1)) : 0;
}

class SegTree {
public:
    const int UNKNOWN = -1;
    SegTree(int n_) {
        n = n_;

        N = 1 << (log2(n) + 1);

        rangeL = vector<int>(N * 2, -1);
        rangeR = vector<int>(N * 2, -1);

        tree = vector<int>(N * 2, 0);

        for (int i = 0; i < N; i++) {
            rangeL[N + i] = rangeR[N + i] = i;
        }

        for (int i = N - 1; i > 0; i--) {
            rangeL[i] = rangeL[left(i)];
            rangeR[i] = rangeR[right(i)];
        }
    }

    int query(int l, int r) {
        return do_query(1, 0, N - 1, l, r);
    }

    void set(int l, int r, int value) {
        // print("Set: " << l << ' ' << r << ' ' << value);
        return do_set(1, 0, N - 1, l, r, value);
    }
private:
    int do_query(int cur, int ll, int rr, int l, int r) {
        assert(rangeL[cur] == ll);
        assert(rangeR[cur] == rr);
        if (ll <= l && r <= rr && tree[cur] != UNKNOWN) {
            return tree[cur] * (r - l + 1);
        } else if (l <= ll && rr <= r && tree[cur] != UNKNOWN) {
            return tree[cur] * (rr - ll + 1);
        }
        assert(ll != rr);

        if (tree[cur] != UNKNOWN) {
            pushDown(cur);
        }

        int mm = (ll + rr) >> 1;
        int res = 0;
        if (l <= mm) {
            res += do_query(left(cur), ll, mm, l, min(r, mm));
        }
        if (r > mm) {
            res += do_query(right(cur), mm + 1, rr, max(mm + 1, l), r);
        }
        pushUp(cur);
        return res;
    }

    void do_set(int cur, int ll, int rr, int l, int r, int value) {
        assert(rangeL[cur] == ll);
        assert(rangeR[cur] == rr);

        int len = rr - ll + 1;

        if (l <= ll && rr <= r) {
            tree[cur] = value;
            return;
        }
        assert(ll != rr);
        if (tree[cur] != UNKNOWN) {
            pushDown(cur);
        }

        int mm = (ll + rr) >> 1;
        if (l <= mm) {
            do_set(left(cur), ll, mm, l, min(mm, r), value);
        }
        if (r > mm) {
            do_set(right(cur), mm + 1, rr, max(mm + 1, l), r, value);
        }
        pushUp(cur);
    }

    void pushUp(int cur) {
        assert(!isLeaf(cur));
        tree[cur] = UNKNOWN;
        if (tree[left(cur)] == tree[right(cur)]) {
            tree[cur] = tree[left(cur)];
        }
    }

    void pushDown(int cur) {
        assert(!isLeaf(cur));
        assert(tree[cur] != UNKNOWN);
        tree[left(cur)] = tree[right(cur)] = tree[cur];
    }
private:
    int left(int x) { return x * 2; }
    int right(int x) { return x * 2 + 1; }
    int parent(int x) { return x / 2; }
    bool isLeaf(int x) { return x >= N; }
private:
    vector<int> rangeL;
    vector<int> rangeR;
    vector<int> tree;
    int n;
    int N;

};

int getPosition(SegTree& st, int l, int r, int c) {
    int b = l;
    while (l <= r) {
        int mid = (l + r) >> 1;
        int slots = mid - b + 1;
        int f = st.query(b, mid);
        if (slots - f >= c) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    int T;
    int case_ = 0;
    input(T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);

        SegTree st(n);

        int a, b, c;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &c);

            if (a == 1) {
                b++;
                int maxi = (n - b + 1) - st.query(b, n);
                c = min(maxi, c);
                int ll = getPosition(st, b, n, 1);
                int rr = getPosition(st, b, n, c);
                if (c == 0) {
                    puts("Can not put any one.");
                } else {
                    st.set(ll, rr, 1);
                    printf("%d %d\n", ll - 1, rr - 1);
                }
            } else if (a == 2) {
                b++;
                c++;
                int f = st.query(b, c);
                printf("%d\n", f);
                st.set(b, c, 0);
            } else {
                assert(false);
            }

            /*
            for (int i = 1; i <= n; i++) {
                printf("%d ", st.query(i, i));
            }
            puts("");
            */

        }
        puts("");
    }

    return 0;
}
