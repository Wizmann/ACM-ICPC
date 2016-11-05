#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 111;

int n;
int board[SIZE][SIZE];

int main() {
    input(n);
    string s;
    for (int i = 0; i < n; i++) {
        input(s);
        for (int j = 0; j < n; j++) {
            board[i][j] = s[j] - '0';
        }
    }
    
    const int mx[] = {-1, 0, 1, 0};
    const int my[] = {0, -1, 0, 1};
    vector<pair<int, int> > cavities;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            int maxi = 0;
            for (int k = 0; k < 4; k++) {
                maxi = max(maxi, board[i + my[k]][j + mx[k]]);
            }
            if (maxi < board[i][j]) {
                cavities.push_back({i, j});
            }
        }
    }
    
    for (auto cavity: cavities) {
        int y = cavity.first;
        int x = cavity.second;
        board[y][x] = -1;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != -1) {
                printf("%d", board[i][j]);
            } else {
                printf("X");
            }
        }
        puts("");
    }
    
    return 0;
}
