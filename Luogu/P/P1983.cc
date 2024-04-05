#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1234;

int mp[SIZE][SIZE];
vector<int> g[SIZE];

int main() {
    int n, m;
    input(n >> m);

    for (int i = 0; i < m; i++) {
        int k;
        scanf("%d", &k);
        vector<int> ms(k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &ms[j]);
        }
        int l = ms[0];
        int r = ms[k - 1];

        int ptr = 0;
        for (int j = l; j <= r; j++) {
            while (ptr < ms.size() && j > ms[ptr]) {
                ptr += 1;
            }
            if (ms[ptr] != j) {
                for (auto num: ms) {
                    mp[j][num] = 1;
                }
            }
        }
    }

    vector<int> ind(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mp[i][j]) {
                ind[j]++;
                g[i].push_back(j);
            }
        }
    }

    vector<int> q[2];
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            q[0].push_back(i);
        }
    }

    vector<bool> visited(n + 1, false);
    int ptr = 0;
    int cnt = 0;
    while (!q[ptr].empty()) {
        int qtr = ptr ^ 1;
        cnt++;
        q[qtr].clear();

        for (auto cur: q[ptr]) {
            // printf("%d ", cur);
            visited[cur] = 1;
            for (auto nxt: g[cur]) {
                ind[nxt] -= 1;
            }
        }
        // puts("");

        for (int i = 1; i <= n; i++) {
            if (ind[i] == 0 && !visited[i]) {
                q[qtr].push_back(i);
            }
        }
        ptr = qtr;
    }
    print(cnt);

    return 0;
}
