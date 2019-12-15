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
    SegTree(const vector<int>& ns) {
        n = ns.size();

        N = 1 << (log2(n) + 1);

        rangeL = vector<int>(N * 2, -1);
        rangeR = vector<int>(N * 2, -1);

        tree = vector<int>(N * 2, UNKNOWN);

        for (int i = 0; i < N; i++) {
            rangeL[N + i] = rangeR[N + i] = i;
        }

        for (int i = N - 1; i > 0; i--) {
            rangeL[i] = rangeL[left(i)];
            rangeR[i] = rangeR[right(i)];
        }
    }

    int query(int cur) {
        return do_query(1, 0, N - 1, cur);
    }

    void update(int l, int r, int value) {
        do_update(1, 0, N - 1, l, r, value);
    }
private:
    int do_query(int p, int l, int r, int cur) {
        if (isLeaf(p)) {
            return tree[p];
        }
        if (tree[p] != UNKNOWN && l <= cur && cur <= r) {
            return tree[p];
        }
        assert(l == rangeL[p]);
        assert(r == rangeR[p]);
        int m = (l + r) >> 1;
        if (cur <= m) {
            return do_query(left(p), l, m, cur);
        } else {
            return do_query(right(p), m + 1, r, cur);
        }
    }

    void do_update(int p, int ll, int rr, int l, int r, int value) {
        if (tree[p] != UNKNOWN) {
            pushDown(p);
        }
        if (l <= ll && rr <= r) {
            tree[p] = value;
            return;
        } else {
            int m = (ll + rr) >> 1;
            if (l <= m) {
                do_update(left(p), ll, m, l, r, value);
            }
            if (r > m) {
                do_update(right(p), m + 1, rr, l, r, value);
            }
        }
        pushUp(p);
    }

    void pushDown(int p) {
        if (isLeaf(p)) {
            return;
        }
        tree[left(p)] = tree[right(p)] = tree[p];
        tree[p] = UNKNOWN;
    }

    void pushUp(int p) {
        if (isLeaf(p)) {
            return;
        }
        if (tree[left(p)] == tree[right(p)]) {
            tree[p] = tree[left(p)];
        } else {
            tree[p] = UNKNOWN;
        }
    }
private:
    bool isLeft(int x) { return x % 2 == 1; }
    bool isRight(int x) { return x % 2 == 0; }
    bool isNeighbor(int x, int y) { return (x ^ y ^ 1) == 0; }
    int left(int x) { return x * 2; }
    int right(int x) { return x * 2 + 1; }
    int sibling(int x) { return x ^ 1; }
    int parent(int x) { return x / 2; }
    bool isLeaf(int x) { return x >= N; }
private:
    vector<int> rangeL;
    vector<int> rangeR;
    vector<int> tree;
    int n;
    int N;

};

class Company {
public:
    Company(int n_) {
        n = n_;
        g.resize(n + 1);
        cnt.resize(n + 1);
        indegree.resize(n + 1);
    }

    void Add(int a, int b) {
        g[b].push_back(a);
        indegree[a]++;
    }

    vector<int> GetDFSOrder() {
        vector<int> res;

        int boss = -1;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                boss = i;
            }
        }
        assert(boss > 0);

        dfs(boss, res);

        for (int i = 1; i <= n; i++) {
            mp[res[i]] = i;
        }
        return res;
    }

    pair<int, int> GetSubTreeRange(int x) {
        int l = mp[x];
        int r = l + cnt[x] - 1;
        return {l, r};
    }
private:
    int dfs(int cur, vector<int>& order) {
        order.push_back(cur);
        for (auto nxt: g[cur]) {
            cnt[cur] += dfs(nxt, order);
        }
        cnt[cur]++;
        return cnt[cur];
    }
private:
    vector<vector<int> > g;
    vector<int> cnt;
    vector<int> indegree;
    map<int, int> mp;
    int n;
};

int main() {

    int T;
    int case_ = 0;
    input(T);
    while (T--) {
        printf("Case #%d:\n", ++case_);
        int n;
        input(n);

        Company com(n);

        int a, b;
        for (int i = 0; i < n - 1; i++) {
            scanf("%d%d", &a, &b);
            com.Add(a, b);
        }

        vector<int> ns = com.GetDFSOrder();
        SegTree st(ns);

        int q;
        input(q);

        char cmd[10];
        while (q--) {
            scanf("%s", cmd);
            if (cmd[0] == 'C') {
                scanf("%d", &a);
                pair<int, int> lr = com.GetSubTreeRange(a);
                printf("%d\n", st.query(lr.first + 1));
            } else if (cmd[0] == 'T') {
                scanf("%d%d", &a, &b);
                pair<int, int> lr = com.GetSubTreeRange(a);
                st.update(lr.first + 1, lr.second + 1, b);
                /*
                for (int i = lr.first + 1; i <= lr.second + 1; i++) {
                    printf("%d ", st.query(i));
                }
                puts("");
                */
            } else {
                assert(false);
            }
        }
    }

    return 0;
}
