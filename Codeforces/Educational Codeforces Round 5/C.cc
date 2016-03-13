#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1111;

const int my[] = {-1, 0, 1, 0};
const int mx[] = {0, 1, 0, -1};

struct Node {
    int f;
    int size;
};

int n, m;
char board[SIZE][SIZE];
Node father[SIZE * SIZE];

int get_idx(int y, int x) {
    return y * m + x;
}

int find_father(int x) {
    if (father[x].f == x) {
        return x;
    }
    return father[x].f = find_father(father[x].f);
}

void do_make_union(int a, int b) {
    a = find_father(a);
    b = find_father(b);
    
    if (a == b) {
        return;
    }
    
    father[a].size += father[b].size;
    father[b].f = a;
}

void make_union(int y0, int x0, int y1, int x1) {
    int a = get_idx(y0, x0);
    int b = get_idx(y1, x1);
    do_make_union(a, b);
}

bool in_board(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < m;
}

int main() {
    input(n >> m);
    for (int i = 0; i < n; i++) {
        scanf("%s", board[i]);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '*') {
                continue;
            }
            int f = get_idx(i, j);
            father[f] = {f, 1};
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '*') {
                continue;
            }

            for (int k = 0; k < 4; k++) {
                int ny = i + my[k];
                int nx = j + mx[k];
                if (in_board(ny, nx) && board[ny][nx] == '.') {
                    make_union(i, j, ny, nx);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != '*') {
                continue;
            }
            set<int> st;
            int res = 0;
            for (int k = 0; k < 4; k++) {
                int ny = i + my[k];
                int nx = j + mx[k];
                if (in_board(ny, nx) && board[ny][nx] == '.') {
                    int f = find_father(get_idx(ny, nx));
                    if (st.find(f) != st.end()) {
                        continue;
                    }
                    st.insert(f);
                    res += father[f].size;
                }
            }
            res = (res + 1) % 10;
            board[i][j] = '0' + res;
        }
    }

    for (int i = 0; i < n; i++) {
        puts(board[i]);
    }
    return 0;
}
