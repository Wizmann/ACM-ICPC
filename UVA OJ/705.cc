#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 512;

vector<int> g[SIZE * SIZE];
int n, m;
char maze[SIZE][SIZE];
char visit[SIZE * SIZE];

int node_id(int y, int x) {
    return y * SIZE + x;
}

void add_node(int y, int x, int b, int a) {
    // printf("(%d, %d) -> (%d, %d)\n", y, x, b, a);
    int p1 = node_id(y, x);
    int p2 = node_id(b, a);
    g[p1].push_back(p2);
    g[p2].push_back(p1);
}

void init() {
    memset(visit, 0, sizeof(visit));
    memset(maze, 0, sizeof(maze));
    for (auto& cnc: g) {
        cnc.clear();
    }
}

int dfs(int p, int pre, int cnt) {
    if (visit[p]) {
        return cnt;
    }
    visit[p] = 1;
    for (auto& next: g[p]) {
        if (next == pre) {
            continue;
        }
        int len = dfs(next, p, cnt + 1);
        if (len) {
            return len;
        }
    }
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    int cas = 0;
    while (input(m >> n) && n + m) {
        init();
        for (int i = 0; i < n; i++) {
            scanf("%s", maze[i]);
        }

        for (int i = 0; i < n * 2; i++) {
            for (int j = 1; j <= m; j++) {
                if (i % 2 == 0) {
                    char p = maze[i / 2][j - 1];
                    if (p == '\\') {
                        add_node(i, j, i + 1, j);
                    } else {
                        add_node(i, j, i + 1, j - 1);
                    }
                } else {
                    char p = maze[i / 2][j - 1];
                    char q = maze[i / 2][j];
                    if (p == '/') {
                        add_node(i, j, i + 1, j);
                    }
                    if (q == '\\') {
                        add_node(i, j, i + 1, j + 1);
                    }
                }
            }
        }
        
        int ans = 0;
        int max_len = 0;
        for (int i = 0; i < n * 2; i++) {
            for (int j = 0; j <= m; j++) {
                if (visit[node_id(i, j)]) {
                    continue;
                }
                int len = dfs(node_id(i, j), -1, 0);
                if (len) {
                    ans++;
                    max_len = max(max_len ,len);
                }
            }
        }
        printf("Maze #%d:\n", ++cas);
        if (ans) {
            printf("%d Cycles; the longest has length %d.\n", ans, max_len);
        } else {
            puts("There are no cycles.");
        }
        puts("");
        // fucking UVA! fucking this weird input/output judgement!
    }
    return 0;
}
