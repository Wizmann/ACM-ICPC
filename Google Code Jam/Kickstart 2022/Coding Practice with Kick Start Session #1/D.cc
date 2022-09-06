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

const int SIZE = 123;
const int COLOR_R = 0;
const int COLOR_B = 1;

struct Point {
    int y, x;
};

char board[SIZE][SIZE];

int n;

const int my[] = {-1, -1, 0, 0, 1, 1};
const int mx[] = {0, 1, -1, 1, -1, 0};

const int TARJAN_SIZE = 12345;
const int TARJAN_EDGE = SIZE * 12 + 23456;

struct Tarjan {

    vector<int> g[TARJAN_SIZE];
    int n,m;
    int dfn[TARJAN_SIZE],low[TARJAN_SIZE];
    stack<int> st;
    int bio[TARJAN_SIZE];
    int lv,sum;
    set<pair<int,int> > road;
    char visit[TARJAN_SIZE];

    void init()
    {
        lv=sum=0;
        for(int i=0;i<TARJAN_SIZE;i++) g[i].clear();
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        st=stack<int>();
        memset(bio,0,sizeof(bio));
        memset(visit,0,sizeof(visit));
    }

    void tarjan(int v,int pre)
    {
        dfn[v]=low[v]=++lv;
        st.push(v);
        for(int i=0;i<(int)g[v].size();i++)
        {
            int u=g[v][i];
            if(u==pre) continue;
            if(!dfn[u])
            {
                tarjan(u,v);
                low[v]=min(low[v],low[u]);
            }
            else low[v]=min(low[v],dfn[u]);
        }

        if(low[v]==dfn[v])
        {
            int t;
            sum++;
            do
            {
                t=st.top();
                st.pop();
                bio[t]=sum;
            }while(t!=v);
        }
    }
};

Tarjan t;

void make_g1(int start, int end, vector<int>& ps) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int y = i;
            int x = j;
            const int idx1 = y * n + x + 1;
            if (board[y][x] != COLOR_B) {
                continue;
            }
            if (x == 0) {
                t.g[start].push_back(idx1);
                t.g[idx1].push_back(start);
            }
            if (x == n - 1) {
                t.g[end].push_back(idx1);
                t.g[idx1].push_back(end);
            }
            ps.push_back(idx1);
            for (int k = 0; k < 6; k++) {
                int ny = y + my[k];
                int nx = x + mx[k];

                if (ny < 0 || nx < 0 || ny >= n || nx >= n || board[ny][nx] != COLOR_B) {
                    continue;
                }

                int idx2 = ny * n + nx + 1;

                t.g[idx1].push_back(idx2);
                t.g[idx2].push_back(idx1);
            }
        }
    }
}

void make_g2(int start, int end, vector<int>& ps) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int y = i;
            int x = j;
            const int idx1 = y * n + x + 1;
            if (board[y][x] != COLOR_R) {
                continue;
            }
            if (y == 0) {
                t.g[start].push_back(idx1);
                t.g[idx1].push_back(start);
            }
            if (y == n - 1) {
                t.g[end].push_back(idx1);
                t.g[idx1].push_back(end);
            }
            ps.push_back(idx1);
            for (int k = 0; k < 6; k++) {
                int ny = y + my[k];
                int nx = x + mx[k];

                if (ny < 0 || nx < 0 || ny >= n || nx >= n || board[ny][nx] != COLOR_R) {
                    continue;
                }

                int idx2 = ny * n + nx + 1;

                t.g[idx1].push_back(idx2);
                t.g[idx2].push_back(idx1);
            }
        }
    }

}

bool check1(int color) {
    t.init();

    const int start = 0;
    const int end = n * n + 1;
    vector<int> ps = {start, end};

    if (color == COLOR_B) {
        make_g1(start, end, ps);
    } else {
        make_g2(start, end, ps);
    }

    for (auto idx : ps) {
        if (!t.dfn[idx]) {
            t.tarjan(idx, -1);
        }
    }

    if (t.bio[start] == t.bio[end]) {
        return false;
    }

    return true;
}

bool visited[SIZE][SIZE];

void dfs2(int y, int x, int color) {
    if (visited[y][x]) {
        return;
    }
    visited[y][x] = true;
    for (int i = 0; i < 6; i++) {
        int ny = y + my[i];
        int nx = x + mx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n || board[ny][nx] != color) {
            continue;
        }
        dfs2(ny, nx, color);
    }
}

bool check2(int color) {
    memset(visited, 0, sizeof(visited));

    if (color == COLOR_B) {
        for (int i = 0; i < n; i++) {
            if (board[i][0] == COLOR_B) {
                dfs2(i, 0, COLOR_B);
            }
        }
        for (int i = 0; i < n; i++) {
            if (visited[i][n - 1]) {
                return true;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (board[0][i] == COLOR_R) {
                dfs2(0, i, COLOR_R);
            }
        }
        for (int i = 0; i < n; i++) {
            if (visited[n - 1][i]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int T;
    input(T);

    for (int case_ = 0; case_ < T; case_++) {
        input(n);

        for (int i = 0; i < n; i++) {
            scanf("%s", board[i]);
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'B') {
                    board[i][j] = COLOR_B;
                } else if (board[i][j] == 'R') {
                    board[i][j] = COLOR_R;
                }
            }
        }

        int b_cnt = 0;
        int r_cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                assert(board[i][j] == COLOR_B
                        || board[i][j] == COLOR_R);
                if (board[i][j] == COLOR_B) {
                    b_cnt++;
                } else if (board[i][j] == COLOR_R) {
                    r_cnt++;
                }
            }
        }

        bool b_valid = check1(COLOR_B);
        bool r_valid = check1(COLOR_R);

        bool b_win = check2(COLOR_B);
        bool r_win = check2(COLOR_R);

        bool valid = (b_valid && r_valid);

        // print(b_cnt, r_cnt, b_valid, r_valid, b_win, r_win);

        if (b_win && r_win) {
            valid = false;
        }

        if (b_cnt == r_cnt) {
            // pass
        } else if (b_cnt == r_cnt + 1) {
            if (r_win) {
                valid = false;
            }
        } else if (r_cnt == b_cnt + 1) {
            if (b_win) {
                valid = false;
            }
        } else {
            valid = false;
        }


        printf("Case #%d: ", case_ + 1);
        if (valid == false) {
            puts("Impossible");
        } else if (r_win) {
            puts("Red wins");
        } else if (b_win) {
            puts("Blue wins");
        } else {
            puts("Nobody wins");
        }
    }

    return 0;
}

/*

^^^TEST^^^
7
1
.
1
B
1
R
2
BR
BB
4
BBBB
BBB.
RRR.
RRRR
4
BBBB
BBBB
RRR.
RRRR
6
......
..R...
BBBBBB
..R.R.
..RR..
......
-----
Case #1: Nobody wins
Case #2: Blue wins
Case #3: Red wins
Case #4: Impossible
Case #5: Blue wins
Case #6: Impossible
Case #7: Blue wins
$$$TEST$$$

^^^TEST^^^
1
3
RRR
...
...
----
Case #1: Impossible
$$$TEST$$$

*/
