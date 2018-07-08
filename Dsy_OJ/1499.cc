/*$$$
[Description]
Given a maze of N * M (1 <= N, M <= 333). You start from point (Y, Z). And in each time period, you can go up/down/left/right for t steps. But you can cross the border and the hinders in the maze.

Please find out the max steps you can move in the maze.

[Tags]
DP, monotone

[Difficulty]
3

[Url]
https://www.lydsy.com/JudgeOnline/problem.php?id=1499
$$$*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int INF = 0x3f3f3f3f;
const int NINF = 0xf3f3f3f3;
const int SIZE = 333;

struct Node {
    int st, end, dir;

    Node(int st_, int end_, int dir_): st(st_), end(end_), dir(dir_) {
        // pass
    }

    bool operator < (const Node& other) const {
        return st < other.st;
    }
};

int n, m, x, y, k;
char board[SIZE][SIZE];
int dp[2][SIZE][SIZE];
vector<Node> nodes;

const int my[] = {INF, -1, 1, 0, 0};
const int mx[] = {INF, 0, 0, -1, 1};

int dis(const pair<int, int>& pa, const pair<int, int>& pb) {
    if (pa.first == pb.first) {
        return abs(pa.second - pb.second);
    } else {
        return abs(pa.first - pb.first);
    }
}

void show(int idx) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", dp[idx][i][j] < 0? -1: dp[idx][i][j]);
        }
        puts("");
    }
    puts("===");
}

int main() {
    input(n >> m >> y >> x >> k);

    for (int i = 1; i <= n; i++) {
        scanf("%s", &board[i][1]);
    }

    int a, b, c;
    for (int i = 0; i < k; i++) {
        scanf("%d%d%d", &a, &b, &c);
        nodes.push_back(Node(a, b, c));
    }

    memset(dp, NINF, sizeof(dp));
    dp[0][y][x] = 0;

    int p = 0;
    int q = 0;
    for (int i = 0; i < k; i++) {
        int delta = nodes[i].end - nodes[i].st + 1;
        int dir = nodes[i].dir;
        q = p ^ 1;
        memset(dp[q], NINF, sizeof(dp[q]));

        vector<pair<int, int> > ps;
        switch (dir) {
            case 1:
                for (int j = 1; j <= m; j++) {
                    ps.push_back(pair<int, int>(n, j));
                }
                break;
            case 2:
                for (int j = 1; j <= m; j++) {
                    ps.push_back(pair<int, int>(1, j));
                }
                break;
            case 3:
                for (int j = 1; j <= n; j++) {
                    ps.push_back(pair<int, int>(j, m));
                }
                break;
            case 4:
                for (int j = 1; j <= n; j++) {
                    ps.push_back(pair<int, int>(j, 1));
                }
                break;
        }

        for (int j = 0; j < ps.size(); j++) {
            pair<int, int> cur = ps[j];

            deque<pair<int, int> > dq;

            while (cur.first > 0 && cur.first <= n && cur.second > 0 && cur.second <= m) {
                if (board[cur.first][cur.second] == 'x') {
                    dq.clear();
                    cur.first += my[dir];
                    cur.second += mx[dir];
                    continue;
                }
                dp[q][cur.first][cur.second] = dp[p][cur.first][cur.second];

                while (!dq.empty() && dis(dq.front(), cur) > delta) {
                    dq.pop_front();
                }

                if (!dq.empty()) {
                    dp[q][cur.first][cur.second] = max(
                            dp[q][cur.first][cur.second],
                            dp[p][dq.front().first][dq.front().second] +
                                dis(cur, dq.front()));
                }

                while (!dq.empty() && dp[p][cur.first][cur.second] >= dp[p][dq.back().first][dq.back().second] + dis(cur, dq.back())) {
                    dq.pop_back();
                }
                dq.push_back(cur);

                cur.first += my[dir];
                cur.second += mx[dir];
            }
        }

        // show(q);
        p = q;
    }

    int ans = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = max(ans, dp[p][i][j]);
        }
    }
    print(ans);
    return 0;
}
