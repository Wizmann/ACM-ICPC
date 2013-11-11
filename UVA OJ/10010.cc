// Result: 12565708	10010	Where's Waldorf?	Accepted	C++	0.286	2013-10-26 14:41:30
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const size_t ALPHA = 26;
const size_t TRIE_SIZE = 102400;
const size_t MAZE_SIZE = 100;
const size_t QUERY_SIZE = 24;
const int DIRS = 8;

const int mx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int my[] = {-1, -1, 0, 1, 1, 1, 0, -1};

struct node {
    int next[ALPHA];
    int mark;
    vector<int> ends;

    void init()
    {
        memset(next, -1, sizeof(next));
        mark = -1;
        ends.clear();
    }
};

struct point {
    int x, y;

    void init()
    {
        x = y = -1;
    }
};

int idx;
char maze[MAZE_SIZE][MAZE_SIZE];
node trie[TRIE_SIZE];
point ans[QUERY_SIZE];
int n, m, q;

int trie_next(int ptr, char nc, int y, int x, int sy, int sx)
{
    int next = trie[ptr].next[nc - 'a'];
    if (trie[next].mark != -1) {
        for (int i = 0; i < (int)trie[next].ends.size(); i++) {
            int e = trie[next].ends[i];
            if (ans[e].x == -1) {
                ans[e].x = sx;
                ans[e].y = sy;
            }
        }
    }
    return next;
}

void solve(int y, int x, int dir) 
{
	int sy = y, sx = x;
    int ptr = 0;
    while(1) {
        if (y < 0 || y >= n || x < 0 || x >= m) {
            break;
        }
        ptr = trie_next(ptr, maze[y][x], y, x, sy, sx);
        if (-1 == ptr) break;

        y += my[dir];
        x += mx[dir];
    }
}

void build_trie(const char* query, int mark, int ptr)
{
    if (!*query) {
        trie[ptr].ends.push_back(mark);
        trie[ptr].mark = mark;
    } else {
        int c = *query - 'a', nx;
        if (-1 == trie[ptr].next[c]) {
            trie[ptr].next[c] = ++idx;
        }
        nx = trie[ptr].next[c];
        build_trie(query + 1, mark, nx);
    }
}

int main()
{
	freopen("input.txt", "r", stdin);
    int T;
    char query[MAZE_SIZE];
    input(T);
    while (T--) {
        idx = 0;
        for (int i = 0; i < (int)TRIE_SIZE; i++) {
            trie[i].init();
        }
        for (int i = 0; i < (int)QUERY_SIZE; i++) {
            ans[i].init();
        }
        input(n >> m);
        for (int i = 0; i < n; i++) {
            scanf("%s", maze[i]);
            for (int j = 0; j < m; j++) {
                if (maze[i][j] >= 'A' &&
                    maze[i][j] <= 'Z') {
                    maze[i][j] ^= 32;
                }
            }
        }
        input(q);
        for (int i = 0; i < q; i++) {
            input(query);
            for (int j = 0; query[j]; j++) {
				if (query[j] >= 'A' && query[j] <= 'Z') {
					query[j] ^= 32;
				}
			}
            build_trie(query, i, 0);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
				for (int k = 0; k < DIRS; k++) {
					solve(i, j, k);
				}
            }
        }

        for (int i = 0; i < q; i++) {
            printf("%d %d\n", ans[i].y + 1, ans[i].x + 1);
        }
        if (T) puts("");
    }
    return 0;
}

