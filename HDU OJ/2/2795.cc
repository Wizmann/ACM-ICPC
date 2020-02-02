#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1 << 18;

class SegTree {
public:
    SegTree(int n_) : n(n_) {
        tree = vector<int>(SIZE * 2 + 123, 0);
    }

    void init(const vector<int>& ns) {
        assert(ns.size() == n);
        for (int i = 0; i < n; i++) {
            tree[SIZE + i] = ns[i];
        }

        for (int i = SIZE - 1; i >= 1; i--) {
            tree[i] = max(tree[left(i)], tree[right(i)]);
        }
    }

    void update(int pos, int value) {
        pos = SIZE + pos;
        tree[pos] = value;
        pos = parent(pos);
        while (pos > 0) {
            tree[pos] = max(tree[left(pos)], tree[right(pos)]);
            pos = parent(pos);
        }
    }

    int query(int value) {
        return do_query(root, 0, SIZE - 1, value);
    }
private:
    int do_query(int cur, int L, int R, int value) {
        if (isLeaf(cur)) {
            if (tree[cur] >= value) {
                return cur - SIZE;
            } else {
                return -1;
            }
        }

        if (tree[cur] < value) {
            return -1;
        }

        int M = (L + R) >> 1;
        int res1 = do_query(left(cur), L, M, value);
        if (res1 != -1) {
            return res1;
        }
        int res2 = do_query(right(cur), M + 1, R, value);
        if (res2 != -1) {
            return res2;
        }

        assert(false);
        return -1;
    }
private:
    int isLeaf(int x) { return x >= SIZE; }
    int left(int x) { return 2 * x; }
    int right(int x) { return 2 * x + 1; }
    int parent(int x) { return x / 2; }
    const int root = 1;
private:
    int n;
    vector<int> tree;
};

int main() {
    int h, w, n;
    while (input(h >> w >> n)) {
        h = min(h, n);
        SegTree stree(h);
        vector<int> ns(h, w);
        stree.init(ns);

        int post;
        for (int i = 0; i < n; i++) {
            scanf("%d", &post);
            int u = stree.query(post);
            if (u == -1) {
                puts("-1");
            } else {
                assert(ns[u] >= post);
                ns[u] -= post;
                stree.update(u, ns[u]);
                printf("%d\n", u + 1);
            }
        }
    }
    return 0;
}
