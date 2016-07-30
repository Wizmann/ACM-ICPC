#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x
#define loop(i, n) for (int i = 0; i < n; i++) 

const int N = 24;
const int SIZE = 200;

char dp[N][N][SIZE][SIZE];
vector<int> ns;

int main() {
    int n, a, b;
    memset(dp, 0, sizeof(dp));
    input(n >> a >> b);
    ns = vector<int>(n);
    loop(i, n) {
        input(ns[i]);
        ns[i]++;
    }
    dp[0][ns[0]][0][0] = 1;
    
    loop(i, n - 2) {
        loop(j, N) {
            loop(k, SIZE) {
                loop(l, k + 1) {
                    if (dp[i][j][k][l] == 0) {
                        continue;
                    }
                    loop(m, SIZE) {
                        if (b * m >= j && m + k < SIZE) {
                            int r = max(0, ns[i + 1] - b * l - a * m);
                            dp[i + 1][r][m + k][m] = 1;
                        }
                    }
                }
            }
        }
    }
    
    loop(i, SIZE) {
        loop(j, i + 1) {
            if (dp[n - 2][0][i][j] && j * b >= ns[n - 1]) {
                print(i);
                goto END;
            }
        }
    }
END: /* pass */;
    return 0;
}
