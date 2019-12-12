// 单点修改，区间查询

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
 
const int M = 1 << 16;

class ZwkSegTree {
public:
    ZwkSegTree(): tree(M * 2) {
        // pass
    }

    void init(const vector<int>& ns) {
        n = ns.size();
        for (int i = 0; i < n; i++) {
            tree[i + M + 1] = ns[i];
        }

        for (int i = M; i >= 1; i--) {
            tree[i] = tree[left(i)] + tree[right(i)];
        }
    }

    void add(int p, int delta) {
        p += M + 1;
        while (p > 0) {
            tree[p] += delta;
            p = parent(p);
        }
    }

    int query(int l, int r) {
        l += M;
        r += M + 2;

        int ans = 0;
        while (parent(l) != parent(r)) {
            if (isLeft(l)) {
                ans += tree[sibling(l)];
            }
            if (isRight(r)) {
                ans += tree[sibling(r)];
            }
            l = parent(l);
            r = parent(r);
        }
        return ans;
    }
private:
    bool isRight(int x) { return x & 1; }
    bool isLeft(int x) { return !isRight(x); }
    int sibling(int x) { return x ^ 1; }
    int left(int x) { return x * 2; }
    int right(int x) { return x * 2 + 1; }
    int parent(int x) { return x / 2; }
private:
    int n;
    vector<int> tree;
};

int main() {
    int T;
    input(T);

    int case_ = 0;

    while (T--) {
        int n;
        input(n);

        printf("Case %d:\n", ++case_);

        vector<int> ns(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        ZwkSegTree st;
        st.init(ns);

        char buffer[100];

        int a, b;
        while (true) {
            scanf("%s", buffer);
            if (buffer[0] == 'E') {
                break;
            }
            switch (buffer[0]) {
                case 'A': {
                    scanf("%d%d", &a, &b);
                    a--;
                    st.add(a, b);
                } break;
                case 'S': {
                    scanf("%d%d", &a, &b);
                    a--;
                    b = -b;
                    st.add(a, b);
                } break;
                case 'Q': {
                    scanf("%d%d", &a, &b);
                    a--; b--;
                    int res = st.query(a, b);
                    printf("%d\n", res);
                } break;
                default:
                    assert(false);
            }
        }
    }
    return 0;
}
