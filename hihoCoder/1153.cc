#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 555;

struct Move {
    int value;
    int y;
    int x;
};

int n;
char num[SIZE];
vector<int> ans;

const int keyboard[5][5] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
   {-1, 0, -1},
};

int get_y(int v) {
    if (v == 0) {
        return 3;
    }
    return (v - 1) / 3;
}

int get_x(int v) {
    if (v == 0) {
        return 1;
    }
    return (v - 1) % 3;
}

bool do_dfs(int ptr, int y, int x, bool flag) {
    if (ptr == n) {
        return true;
    }
    
    vector<Move> moves;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (keyboard[i][j] == -1) {
                continue;
            }
            if (i < y || j < x) {
                continue;
            }
            Move m = {keyboard[i][j], i, j};
            moves.push_back(m);
        }
    }
    
    sort(moves.begin(), moves.end(), [](const Move& m1, const Move& m2) {
        return m1.value > m2.value;
    });
    
    int v = num[ptr] - '0';
    
    for (auto m: moves) {
        if (m.value == -1) {
            continue;
        }
        if (flag && m.value > v) {
            continue;
        }
        ans.push_back(m.value);
        bool ff = flag && (m.value == v);
        if (do_dfs(ptr + 1, m.y, m.x, ff)) {
            return true;
        }
        ans.pop_back();
    }
    return false;
}

void dfs() {
    int v = num[0] - '0';
    for (int i = v; i >= 0; i--) {
        int y = get_y(i);
        int x = get_x(i);
        if (do_dfs(0, y, x, true)) {
            break;
        }
    }
}

int main() {
    int T;
    input(T);
    while (T--) {
        scanf("%s", num);
        n = strlen(num);
        ans.clear();
        
        dfs();
        
        int l = ans.size();
        int ptr = 0;
        while (ptr < l && ans[ptr] == 0) {
            ptr++;
        }
        while (ptr < l) {
            printf("%d", ans[ptr]);
            ptr++;
        }
        puts("");
    }
    return 0;
}
