#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 234567;

int n;
int color[SIZE];
vector<int> g[SIZE];
int treesize[SIZE];
int children[SIZE];
llint ans;

int dfs(int cur, int pre) {
    int cnt = 1;
    int c = color[cur];
    int r = 0;

    int m = g[cur].size();
    for (int i = 0; i < m; i++) {
        int next = g[cur][i];
        if (next == pre) {
            continue;
        }

        int u = children[c];
        int size = dfs(next, cur);
        cnt += size;

        int diff = size - (children[c] - u);
        r += (children[c] - u);
        ans += 1LL * diff * (diff - 1) / 2;
    }

    children[c] += cnt - r;
    return treesize[cur] = cnt;
}

int main() {
    freopen("input.txt", "r", stdin);
    int case_ = 0;
    while (input(n)) {
        printf("Case #%d: ", ++case_);
        for (int i = 0; i < SIZE; i++) {
            g[i].clear();
        }
        memset(treesize, 0, sizeof(treesize));
        memset(children, 0, sizeof(children));
        ans = 0;

        set<int> st;
        for (int i = 0; i < n; i++) {
            scanf("%d", &color[i]);
            st.insert(color[i]);
        }

        int a, b;
        for (int i = 0; i < n - 1; i++) {
            scanf("%d%d", &a, &b);
            a--;
            b--;

            g[a].push_back(b);
            g[b].push_back(a);
        }

        dfs(0, -1);
        for (set<int>::iterator iter = st.begin(); iter != st.end(); ++iter) {
            ans += 1LL * (n - children[*iter]) * (n - children[*iter] - 1) / 2;
        }
        print(1LL * n * (n - 1) / 2 * st.size() - ans);
    }

    return 0;
}
