#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 2345;

int dp[SIZE][SIZE];
int A[SIZE];

string a, b;
int la, lb;

int main()
{
    input(a >> b);
    la = a.size(); lb = b.size();
    memset(A, -1, sizeof(A));
    for (int i = 0; i < la; i++) {
        int p, q;
        for (p = i, q = 0; p < la; p++) {
            if (a[p] == b[q]) {
                q++;
            }
            if (q == lb) {
                A[i] = p - i + 1;
                break;
            }
        }
    }

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i <= la; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);

            if (A[i] != -1) {
                dp[A[i] + i][j + A[i] - lb] = max(dp[A[i] + i][j + A[i] - lb], dp[i][j] + 1);
            }
        }
    }

    for (int i = 0; i <= la; i++) {
        printf("%d ", dp[la][i]);
    }
    puts("");
    return 0;
}
