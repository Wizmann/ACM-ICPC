#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
 
using namespace std;
 
#define print(x) cout << x << endl
#define input(x) cin >> x
 
typedef long long llint;
 
const int SIZE = 1 << 18;
const llint INF = 0x3f3f3f3f3f3f3f3fLL;
 
struct SegTree {
    struct SegTreeNode {
        llint value;
        llint lazy;
    };
public:
    SegTree(int n_) : n(n_) {
        tree = vector<SegTreeNode>(SIZE * 2 + 1);
    }
 
    void init(const vector<llint>& nums) {
        for (int i = 0; i < SIZE; i++) {
            tree[i + SIZE].value = INF;
        }
 
        for (int i = 0; i < n; i++) {
            tree[i + SIZE].value = nums[i];
            tree[i + SIZE].lazy = 0;
        }
 
        for (int i = SIZE - 1; i > 0; i--) {
            tree[i].value = min(tree[left(i)].value, tree[right(i)].value);
            tree[i].lazy = 0;
        }
    }
 
    void modify(int l, int r, int delta) {
        do_modify(root, 0, SIZE - 1, l, r, delta);
    }
 
    llint query() {
        return tree[root].value;
    }
private:
    void do_modify(int cur, int L, int R, int l, int r, llint delta) {
        if (l > r) {
            return;
        }
        if (L == l && R == r) {
            tree[cur].value += delta;
            tree[cur].lazy += delta;
            return;
        }
 
        int M = (L + R) >> 1;
        tree[left(cur)].value += tree[cur].lazy;
        tree[right(cur)].value += tree[cur].lazy;
        tree[left(cur)].lazy += tree[cur].lazy;
        tree[right(cur)].lazy += tree[cur].lazy;
 
        if (r <= M) {
            do_modify(left(cur), L, M, l, r, delta);
        } else if (M < l) {
            do_modify(right(cur), M + 1, R, l, r, delta);
        } else {
            do_modify(left(cur), L, M, l, M, delta);
            do_modify(right(cur), M + 1, R, M + 1, r, delta);
        }
 
        tree[cur].value = min(tree[left(cur)].value, tree[right(cur)].value);
        tree[cur].lazy = 0;
    }
private:
    int parent(int x) { return x / 2; }
    int left(int x) { return 2 * x; }
    int right(int x) { return 2 * x + 1; }
    bool isLeaf(int x) { return x >= SIZE; }
    const int root = 1;
private:
    int n;
    vector<SegTreeNode> tree;
};
 
int main() {
    int n;
    input(n);
    SegTree tree(n + 1);
 
    vector<int> ns(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ns[i]);
    }
 
    vector<int> vs(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &vs[i]);
    }
 
    vector<llint> ps(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        ps[ns[i]] = vs[i];
    }
    for (int i = 1; i <= n; i++) {
        ps[i] += ps[i - 1];
    }
 
    tree.init(ps);
 
    llint ans = INF;
    for (int i = 1; i < n; i++) {
        tree.modify(ns[i], n, -vs[i]);
        tree.modify(0, ns[i] - 1, vs[i]);
        // print(tree.query());
        ans = min(ans, tree.query());
        // print(ans);
    }
 
    print(ans);
 
    return 0;
}
