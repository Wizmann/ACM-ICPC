#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 123456;

vector<int> g[SIZE];

void dfs1(int pre, int cur, int depth, set<int>& st) {
    // is leaf
    if (g[cur].size() == 1 && g[cur][0] == pre) {
        st.insert(depth % 2);
        return;
    }

    llint u = 0;
    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }
        dfs1(cur, nxt, depth + 1, st);
    }
}

bool dfs2(int pre, int cur, int depth, int& tot) {
    // is leaf
    if (g[cur].size() == 1 && g[cur][0] == pre) {
        return true;
    }

    int leaf = 0;
    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }
        leaf += dfs2(cur, nxt, depth + 1, tot);
    }

    if (leaf) {
        tot -= leaf - 1;
    }

    return false;
}

int main() {
    int n;
    input(n);

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int root = -1;
    for (int i = 0; i < n; i++) {
        if (g[i].size() > 1) {
            root = i;
            break;
        }
    }
    assert(root != -1);

    set<int> st1;
    dfs1(-1, root, 0, st1);
    if (st1.size() == 1) {
        a = 1;
    } else {
        a = 3;
    }

    b = n - 1;
    dfs2(-1, root, 0, b);

    printf("%d %d\n", a, b);


    return 0;
}
