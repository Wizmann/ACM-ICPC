#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int INF = 0x3f3f3f3f;
const int SIZE = 333;

int n, m, p;
char board[SIZE][SIZE];

int main() {
    while (input(n >> m >> p) && n + m + p) {
        for (int i = 0; i < n; i++) {
            scanf("%s", board[i]);
        }

        int ans = INF;
        for (int i = 0; i < m; i++) {
            vector<int> ns(n, 0);
            for (int j = i; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    ns[k] += board[k][j] == '.'? 1: 0;
                }

                int l = 0;
                int r = 0;
                int tot = 0;

                while (l < n && r < n) {
                    tot += ns[r];
                    while (tot >= p) {
                        ans = min(ans, (j - i + 1) * (r - l + 1));
                        tot -= ns[l];
                        l += 1;
                    }
                    r += 1;
                }
            }
        }
        print(ans);
    }
    return 0;
}
