// Result: 2014-09-11 00:35:46	Accepted	1081	0MS	412K	1101 B	G++	Wizmann
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
const int SIZE = 128 + 5;

int g[SIZE][SIZE];
int array[SIZE];
int n;

int max_interval(int* dp)
{
    int ans = -INF, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += dp[i];
        ans = max(ans, sum);
        sum = max(sum, 0);
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    while (input(n)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &g[i][j]);
            }
        }

        int ans = -INF;
        for (int i = 0; i < n; i++) {
            memset(array, 0, sizeof(array));
            for (int j = i; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    array[k] += g[k][j];
                }
                ans = max(ans, max_interval(array));
            }
        }
        print(ans);
    }
    return 0;
}


