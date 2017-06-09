#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1111;
const int my[] = {-1, 0, 1, 0};
const int mx[] = {0, 1, 0, -1};

int n, m;
char board[SIZE][SIZE];
int limit[4][SIZE][SIZE];
map<int, pair<int, int> > mp;
vector<pair<int, int> > moves;

int dfs(int y, int x, int dir) {
    if (y < 0 || y >= n || x < 0 || x >= m) {
        return -1;
    }

    if (board[y][x] == '#') {
        return -1;
    }
    
    if (limit[dir][y][x] != -1) {
        return limit[dir][y][x];
    }

    return limit[dir][y][x] = dfs(y + my[dir], x + mx[dir], dir) + 1;
}

bool judge(int y, int x) {
    for (auto move: moves) {
        int dir = move.first;
        int len = move.second;

        if (limit[dir][y][x] >= len) {
            y += my[dir] * len;
            x += mx[dir] * len;
        } else {
            return false;
        }
    }
    return true;
}

int get_dir(char cmd) {
    switch (cmd) {
        case 'N': return 0;
        case 'E': return 1;
        case 'S': return 2;
        case 'W': return 3;
    }
    return -1;
}

int main() {
    input(n >> m);
    for (int i = 0; i < n; i++) {
        scanf("%s", board[i]);
        for (int j = 0; j < m; j++) {
            if ('A' <= board[i][j] && board[i][j] <= 'Z') {
                char c = board[i][j];
                mp[c] = {i, j};
            }
        }
    }

    memset(limit, -1, sizeof(limit));

    for (int dir = 0; dir < 4; dir++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0 ; j < m; j++) {
                dfs(i, j, dir);
            }
        }
    }

    int q;
    int len;
    char cmd[10];
    input(q);

    for (int i = 0; i < q; i++) {
        scanf("%s%d", cmd, &len);
        int dir = get_dir(cmd[0]);
        moves.push_back({dir, len});
    }

    string ans;

    for (auto p: mp) {
        char c = p.first;
        int y = p.second.first;
        int x = p.second.second;

        if (judge(y, x)) {
            ans += c;
        }
    }
    if (ans.empty()) {
        puts("no solution");
    } else {
        print(ans);
    }

    return 0;
}
