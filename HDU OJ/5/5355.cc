#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 312345;

int n, m;
vector<int> g[SIZE];
vector<pair<int, int> > edges;
vector<int> dt;

void solve() {
    int l = 1;
    int r = n;
    set<int> st;
    st.insert(1);

    int step = 0;
    while (!st.empty()) {
        int cur = -1;
        if (l == *st.begin()) {
            cur = l;
            l++;
            st.erase(st.begin());
        } else if (r == *st.rbegin()) {
            cur = r;
            r--;
            st.erase(--st.end());
        } else {
            assert(false);
        }
        
        dt[cur] = step++;

        for (int i = 0; i < g[cur].size(); i++) {
            int next = g[cur][i];
            if (l <= next && next <= r) {
                st.insert(next);
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    input(T);

    while (T--) {
        scanf("%d%d", &n, &m);

        for (int i = 0; i < SIZE; i++) {
            g[i].clear();
        }
        edges.clear();
        dt = vector<int>(n + 1, 0);

        int a, b;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            g[a].push_back(b);
            edges.push_back({a, b});
        }
        
        solve();
        for (int i = 0; i < m; i++) {
            a = edges[i].first;
            b = edges[i].second;

            printf("%d\n", a != b? abs(dt[a] - dt[b]): n);
        }
    }

    return 0;
}

