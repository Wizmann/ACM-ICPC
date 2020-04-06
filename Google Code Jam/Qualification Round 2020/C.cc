#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1111;

vector<int> g[SIZE];
vector<int> result;

bool dfs(int cur, int value) {
    if (result[cur] == -1) {
        result[cur] = value;
    } else {
        return result[cur] == value;
    }

    for (auto nxt : g[cur]) {
        bool res = dfs(nxt, value ^ 1);
        if (res == false) {
            return false;
        }
    }
    return true;
}

int main() {
    int T;
    input(T);

    int a, b;
    int case_ = 0;

    while (T--) {
        for (int i = 0; i < SIZE; i++) {
            g[i].clear();
        }

        int n;

        input(n);
        vector<pair<int, int> > ps;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);
            ps.emplace_back(a, b);
        }

        for (int i = 0; i < n; i++) {
            int a1 = ps[i].first;
            int b1 = ps[i].second;
            for (int j = i + 1; j < n; j++) {
                int a2 = ps[j].first;
                int b2 = ps[j].second;

                if (b1 <= a2 || b2 <= a1) {
                    // pass
                } else {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }

        bool flag = true;
        result = vector<int>(n, -1);
        for (int i = 0; i < n; i++) {
            if (flag == false) {
                break;
            }
            if (result[i] != -1) {
                continue;
            }
            flag = dfs(i, 0);
        }

        printf("Case #%d: ", ++case_);
        if (flag == true) {
            for (auto r : result) {
                if (r == 0) {
                    putchar('C');
                } else {
                    putchar('J');
                }
            }
            puts("");
        } else {
            puts("IMPOSSIBLE");
        }
    }
    return 0;
}
