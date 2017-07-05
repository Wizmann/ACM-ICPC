#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x 

const int SIZE = 1111;
const int INF = 0x3f3f3f3f;

const int my[] = {-1, 0, 1, 0};
const int mx[] = {0, 1, 0, -1};

int m;
int board[SIZE][SIZE];
int dp[SIZE][SIZE];

struct Node {
    Node(int x_, int y_, int step_): x(x_), y(y_), step(step_) {
        // pass
    }
    
    int x, y, step;
};

int main() {
    freopen("input.txt", "r", stdin);
    
    int a, b, c;
    input(m);
    memset(board, INF, sizeof(board));
    memset(dp, INF, sizeof(dp));
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        board[b][a] = min(board[b][a], c);
        for (int j = 0; j < 4; j++) {
            int ny = b + my[j];
            int nx = a + mx[j];
            
            if (ny < 0 || ny >= SIZE || nx < 0 || nx >= SIZE) {
                continue;
            }
            
            board[ny][nx] = min(board[ny][nx], c);
        }
    }

    queue<Node> q;
    q.push(Node(0, 0, 0));

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        int y = cur.y;
        int x = cur.x;
        int step = cur.step;

        if (dp[y][x] <= step) {
            continue;
        }

        dp[y][x] = step;

        for (int i = 0; i < 4; i++) {
            int ny = y + my[i];
            int nx = x + mx[i];

            if (ny < 0 || ny >= SIZE || nx < 0 || nx >= SIZE) {
                continue;
            }

            if (board[ny][nx] <= step + 1) {
                continue;
            }

            q.push(Node(nx, ny, step + 1));
        }
    }

    int ans = INF;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != INF) {
                continue;
            }
            // print(i << ' ' << j << ' ' << board[i][j] << " " << dp[i][j]);
            ans = min(ans, dp[i][j]);
        }
    }

    if (ans == INF) {
        ans = -1;
    }

    print(ans);

    return 0;
}
