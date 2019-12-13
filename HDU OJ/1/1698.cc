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

class SegTree {
public:
    SegTree(const vector<int>& ns) {
        n = ns.size();

        N = n;
        for (int i = N; i > 0; i >>= 1) {
            N |= i;
        }
        N++;

        rangeL = vector<int>(N * 2, -1);
        rangeR = vector<int>(N * 2, -1);

        tree = vector<int>(N * 2, -1);

        for (int i = 0; i < N; i++) {
            rangeL[N + i] = rangeR[N + i] = i;
        }

        for (int i = 0; i < n; i++) {
            tree[N + i] = ns[i];
        }

        for (int i = N - 1; i > 0; i--) {
            rangeL[i] = rangeL[left(i)];
            rangeR[i] = rangeR[right(i)];
            pushUp(i);
        }
    }

    void update(int l, int r, int value) {
        do_update(1, l, r, value);
    }

    int query(int l, int r) {
        return do_query(1, l, r);
    }
private:
    void pushUp(int x) {
        if (tree[left(x)] == tree[right(x)]) {
            tree[x] = tree[left(x)];
        } else {
            tree[x] = -1;
        }
    }

    void pushDown(int x) {
        assert (x < N);
        tree[left(x)] = tree[right(x)] = tree[x];
        tree[x] = -1;
    }

    int do_query(int cur, int l, int r) {
        if (tree[cur] != -1) {
            return (r - l + 1) * tree[cur];
        }

        int m = rangeR[left(cur)];

        int res = 0;
        if (m >= l) {
            res += do_query(left(cur), l, min(r, m));
        }
        if (m + 1 <= r) {
            res += do_query(right(cur), max(l, m + 1), r);
        }
        return res;
    }

    void do_update(int cur, int l, int r, int value) {
        if (rangeL[cur] == l && rangeR[cur] == r) {
            tree[cur] = value;
            return;
        }
        if (tree[cur] != -1) {
            pushDown(cur);
        }
        int m = rangeR[left(cur)];
        if (m >= l) {
            do_update(left(cur), l, min(r, m), value);
        }
        if (m + 1 <= r) {
            do_update(right(cur), max(l, m + 1), r, value);
        }
        pushUp(cur);
    }
private:
    int left(int x) { return x * 2; }
    int right(int x) { return x * 2 + 1; }
    int parent(int x) { return x / 2; }
private:
    vector<int> rangeL;
    vector<int> rangeR;
    vector<int> tree;
    int n;
    int N;
};

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    input(T);
    int case_ = 0;
    while (T--) {
        int n;
        input(n);
        vector<int> ns(n, 1);
        SegTree st(ns);

        /*
        for (int i = 0; i < n; i++) {
            printf("%d ", st.query(i, i));
        }
        puts("");
        */

        int q;
        input(q);

        int a, b, c;
        while (q--) {
            scanf("%d%d%d", &a, &b, &c);
            a--;
            b--;
            st.update(a, b, c);

            /*
            for (int i = 0; i < n; i++) {
                printf("%d ", st.query(i, i));
            }
            puts("");
            */
        }
        printf("Case %d: The total value of the hook is %d.", 
                ++case_, st.query(0, n - 1));
        puts("");
    }
    return 0;
}
