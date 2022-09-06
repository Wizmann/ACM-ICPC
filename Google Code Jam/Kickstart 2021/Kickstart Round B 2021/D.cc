#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1 << 18;

typedef long long llint;

llint gcd(llint a, llint b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

llint mygcd(llint a, llint b) {
    if (a == 0) { return b; }
    if (b == 0) { return a; }
    return gcd(a, b);
}

struct Query {
    int weight, idx;
};

struct Edge {
    int dest;
    int limit;
    llint charge;
};

int n, q;
vector<Edge> g[SIZE];
vector<Query> queries[SIZE];
vector<llint> ans;

class SegmentTree {
public:
    SegmentTree() {
        nodes.resize(SIZE * 4);
        init(0, SIZE, 0);
    }

    void set_value(int pos, llint value) {
        do_set_value(0, SIZE, 0, pos, value);
    }

    llint query(int l, int r) {
        return do_query(0, SIZE, 0, l, r);
    }
private:
    void init(int L, int R, int pos) {
        if (L + 1 == R) {
            return;
        }

        assert(pos < nodes.size());
        nodes[pos].lazy = 0;

        int M = (L + R) / 2;
        init(L, M, left(pos));
        init(M, R, right(pos));
    }

    void do_set_value(int L, int R, int cur, int pos, llint value) {
        if (pos < L || pos >= R) {
            return;
        }

        if (L + 1 == R) {
            assert(L == pos);
            nodes[cur].lazy = value;
            return;
        }

        int M = (L + R) / 2;
        do_set_value(L, M, left(cur), pos, value);
        do_set_value(M, R, right(cur), pos, value);

        nodes[cur].lazy = mygcd(nodes[left(cur)].lazy, nodes[right(cur)].lazy);
    }

    llint do_query(int L, int R, int cur, int l, int r) {
        if (L == R) {
            return 0;
        }
        if (r <= L || l >= R) {
            return 0;
        }
        if (l <= L && R <= r) {
            return nodes[cur].lazy;
        }

        assert(L + 1 != R);

        llint res = 0;

        int M = (L + R) / 2;
        res = mygcd(res, do_query(L, M, left(cur), l, r));
        res = mygcd(res, do_query(M, R, right(cur), l, r));
        return res;
    }

    int left(int x) { return x * 2 + 1; }
    int right(int x) { return x * 2 + 2; }

    struct SegmentTreeNode {
        llint lazy;
    };

    vector<SegmentTreeNode> nodes;
};

void init() {
    for (int i = 0; i < SIZE; i++) {
        g[i].clear();
        queries[i].clear();
    }
    ans = vector<llint>(SIZE, 0);
}

void dfs(SegmentTree& st, int pre, int cur) {
    for (const auto& query : queries[cur]) {
        llint res = st.query(0, query.weight + 1);
        ans[query.idx] = res;
    }

    for (const auto& edge : g[cur]) {
        if (edge.dest == pre) {
            continue;
        }
        st.set_value(edge.limit, edge.charge);
        dfs(st, cur, edge.dest);
        st.set_value(edge.limit, 0);
    }
}

int main() {
    int T;
    input(T);

    int a, b, limit;
    llint charge;

    int pos, weight;

    for (int case_ = 0; case_ < T; case_++) {
        init();

        printf("Case #%d: ", case_ + 1);

        scanf("%d%d", &n, &q);
        /*
        puts("");
        print(n << ' ' << q);
        */

        for (int i = 0; i < n - 1; i++) {
            scanf("%d%d%d%lld", &a, &b, &limit, &charge);
            g[a].push_back({b, limit, charge});
            g[b].push_back({a, limit, charge});
            // print(a << ' ' << b << ' ' << limit << ' ' << charge);
        }


        for (int i = 0; i < q; i++) {
            scanf("%d%d", &pos, &weight);
            // print(pos << ' ' << weight);
            queries[pos].push_back({weight, i});
        }

        SegmentTree st;
        dfs(st, 0, 1);


        for (int i = 0; i < q; i++) {
            printf("%lld ", ans[i]);
        }

        puts("");
    }

    return 0;
}

/*
^^^TEST^^^
2
7 5
2 1 2 4
2 3 7 8
3 4 6 2
5 3 9 9
2 6 1 5
7 1 5 7
5 10
5 8
4 1
6 1
7 6
3 2
1 2 2 10
3 2 3 5
3 2
3 3
----
Case #1: 1 4 0 5 7
Case #2: 10 5
$$$TEST$$$

^^^TEST^^^
1
2 3
1 2 3 4
2 1
2 3
2 4
----
Case #1: 0 4 4
$$$TEST$$$

^^^TEST^^^
2
3 3
1 2 3 4
2 3 4 5
2 1
2 3
2 4
3 3
1 2 3 4
2 3 4 5
2 1
2 3
3 4
----
Case #1: 0 4 4
Case #2: 0 4 1
$$$TEST$$$

^^^TEST^^^
1
3 4
2 1 1 1000000000000000000
3 1 200000 1
2 1
3 200000
2 1
3 200000
1000000000000000000 0 1000000000000000000 0 
----
Case #1: 1000000000000000000 1 1000000000000000000 1 
$$$TEST$$$


 */
