#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 4;

int n;
int board[SIZE][SIZE];
vector<pair<int, int> > ps[SIZE * 2];

inline int maxpos(const vector<int>& ns) {
    assert(ns.size() == SIZE);
    for (int i = SIZE - 1; i >= 0; i--) {
        if (ns[i]) {
            return i;
        }
    }
    return 0;
}

int solve(int idx) {
    int base = 0;
    int ans = 0;
    
    vector<int> lst(SIZE, 0);
    vector<int> rst(SIZE, 0);
    
    for (auto p: ps[idx]) {
        if (p.first == 4) {
            base += 4;
        } else {
            assert(p.first < SIZE);
            assert(p.second < SIZE);
            lst[p.first]++;
            rst[p.second]++;
        }
    }
    
    ans = base;
    
    for (auto p: ps[idx]) {
        if (p.first == 4) {
            continue;
        }
        
        lst[p.first]--;
        rst[p.second]--;
        
        if (!rst.empty()) {
            ans = max(ans, base + p.first + maxpos(rst));
        }
        if (!lst.empty()) {
            ans = max(ans, base + p.second + maxpos(lst));
        }

        lst[p.first]++;
        rst[p.second]++;
    }
    return ans;
}

pair<int, int> calc(int y, int x, int dy, int dx) {
    int l = 0;
    for (int i = y, j = x; 
            0 <= i && i < SIZE && 0 <= j && j < SIZE; 
            i += dy, j += dx) {
        assert(0 <= i && i < SIZE);
        assert(0 <= j && j < SIZE);
        assert(0 <= board[i][j] && board[i][j] <= 1);

        if (board[i][j] == 1) {
            l++;
        } else {
            break;
        }
    }
    assert(l <= SIZE);
    
    int r = 0;
    for (int i = y + (SIZE - 1) * dy, j = x + (SIZE - 1) * dx; 
             0 <= i && i < SIZE && 0 <= j && j < SIZE; 
             i -= dy, j -= dx) {
        assert(0 <= i && i < SIZE);
        assert(0 <= j && j < SIZE);
        assert(0 <= board[i][j] && board[i][j] <= 1);

        if (board[i][j] == 1) {
            r++;
        } else {
            break;
        }
    }
    assert(r <= SIZE);
    // print(l << ' ' << r);
    return {l, r};
}

int main() {
    input(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                scanf("%d", &board[j][k]);
                assert(0 <= board[j][k] && board[j][k] <= 1);
            }
        }
        
        int idx = 0;
        for (int j = 0; j < SIZE; j++) {
            ps[idx].push_back(calc(j, 0, 0, 1));
            idx++;
        }
        
        for (int j = 0; j < SIZE; j++) {
            ps[idx].push_back(calc(0, j, 1, 0));
            idx++;
        }
        assert(idx == SIZE * 2);
    }
    
    int ans = 0;
    
    for (int i = 0; i < 8; i++) {
        ans = max(ans, solve(i));
    }
    
    print(ans);
    
    return 0;
}

