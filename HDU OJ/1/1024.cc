/*
Description:

given array S[1...n]. mark f(i, j) == sum(S[i] + ... S[j])

g(m) equals the sum of m unoverlapped interval, g(m) = f(i1, j1) + f(i2, j2) ... f(im, jm)

calculate the maximum g(m)

Solution:

dp[i][j] means for S[1...j] the maximun g(i) for i intervals

dp[i][j] = max(
        dp[i][j - 1] + S[j],                ........ (1)
        max(dp[i - 1][0...j - 1]) + S[j]    ........ (2)
)

for (1), it means if we already have dp[i][j - 1], there's a way to induct dp[i][j] by adding S[j] to the chosen intervals
for (2), it means we start a new interval S[j...j], and apply the largest g for S[1...j-1]

*/


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int INF = 0x3f3f3f3f;

int main() {
    int m, n;
    while (input(m >> n)) {
        vector<int> ns(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        vector<int> dp[2];

        dp[0] = vector<int>(n, 0);
        dp[1] = vector<int>(n, -INF);

        int p = 0;
        for (int i = 0; i < m; i++) {
            int q = p ^ 1;
            dp[q] = vector<int>(n, -INF);
            for (int j = i; j < n; j++) {
                int t = max(
                        (j - 1 < 0? 0 : dp[q][j - 1]) + ns[j], 
                        (j - 1 < 0? 0 : dp[p][j - 1]) + ns[j]);
                dp[q][j] = max(dp[q][j], t);
            }
            /*
            for (int j = i; j < n; j++) {
                printf("%d ", dp[q][j]);
            }
            puts("");
            */
            for (int j = i + 1; j < n; j++) {
                dp[q][j] = max(dp[q][j], dp[q][j - 1]);
            }
            p = q;
        }

        int maxi = -INF;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, dp[p][i]);
        }
        print(maxi);
    }

    return 0;
}

