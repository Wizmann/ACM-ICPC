#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1024 + 123;

const int mx[] = {0, 1, 0, 1};
const int my[] = {0, 0, 1, 1};
const int MOVE = 4;

int mp[SIZE][SIZE];
int n, m, k;

bool isBlackBlock(int y, int x) {
    int cnt = 0;
    for (int i = 0; i < MOVE; i++) {
        int ny = y + my[i];
        int nx = x + mx[i];

        if (ny >= 0 && ny < n
                && nx >= 0 && nx < m
                && mp[ny][nx]) {
            cnt++;
        }
    }
    return cnt == MOVE;
}


int main() {
    freopen("input.txt", "r", stdin);
    int y, x;
    input(n >> m >> k);
    memset(mp, 0, sizeof(mp));
    int ans = 0;
    for (int i = 0; i < k; i++) {
        input(y >> x);
        x--; y--;
        mp[y][x] = 1;
        bool flag = false;
        for (int j = 0; j < MOVE; j++) {
            flag |= isBlackBlock(y - my[j], x - mx[j]);
        }
        if (flag) {
            ans = i + 1;
            break;
        }
    }
    print(ans);
    return 0;
}

