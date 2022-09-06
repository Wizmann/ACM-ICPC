#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

const int SIZE = 333;

int board[SIZE][SIZE];
char visited[SIZE][SIZE];

struct Point {
    int value;
    int y;
    int x;

    bool operator < (const Point& other) const {
        if (value != other.value) {
            return value < other.value;
        }
        if (y != other.y) {
            return y < other.y;
        }
        return x < other.x;
    }
};

llint solve(int n, int m) {
    priority_queue<Point> q;

    vector<Point> ps;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ps.push_back({board[i][j], i, j});
        }
    }
    sort(ps.begin(), ps.end());
    reverse(ps.begin(), ps.end());
    for (const auto& p : ps) {
        q.push(p);
    }

    memset(visited, 0, sizeof(visited));

    llint res = 0;
    int pre = INF;
    while (!q.empty()) {
        const auto cur = q.top();
        q.pop();
        assert(cur.value <= pre);
        pre = cur.value;
        if (visited[cur.y][cur.x]) {
            continue;
        }
        visited[cur.y][cur.x] = 1;
        // print(">>", cur.value, cur.y, cur.x);

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (i && j) {
                    continue;
                }
                int ny = cur.y + i;
                int nx = cur.x + j;
                if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                    continue;
                }

                int u = board[ny][nx];
                if (u < cur.value - 1) {
                    board[ny][nx] = cur.value - 1;
                    q.push({board[ny][nx], ny, nx});
                    // print(cur.value, u, cur.value - 1 - u);
                    res += (cur.value - 1) - u;
                }
            }
        }
    }
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", board[i][j]);
            for (int ii = -1; ii <= 1; ii++) {
                for (int jj = -1; jj <= 1; jj++) {
                    if (ii == 0 && jj == 0) {
                        continue;
                    }
                    if (ii && jj) {
                        continue;
                    }
                    
                    int ny = i + ii;
                    int nx = j + jj;
                    if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                        continue;
                    }
                    assert(abs(board[ny][nx] - board[i][j]) <= 1);
                    assert(board[i][j] >= 0);
                }
            }
        }
        puts("");
    }
    */
    return res;
}

int main() {
    int T;
    input(T);

    int n, m;
    for (int case_ = 0; case_ < T; case_++) {
        input(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &board[i][j]);
            }
        }

        printf("Case #%d: %lld\n", case_ + 1, solve(n, m));
    }

    return 0;
}

/*

^^^TEST^^^
3
1 3
3 4 3
1 3
3 0 0
3 3
0 0 0
0 2 0
0 0 0
----
Case #1: 0
Case #2: 3
Case #3: 4
$$$TEST$$$

^^^TEST^^^
1
1 1
12345
----
Case #1: 0
$$$TEST$$$

^^^TEST^^^
1
1 2
12345 0 
----
Case #1: 12344
$$$TEST$$$

^^^TEST^^^
1
1 4
0 2 0 0
----
Case #1: 2
$$$TEST$$$

*/
