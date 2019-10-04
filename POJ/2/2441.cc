#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int INF = 0x3f3f3f3f;
const int N = 20;
const int SIZE = (1 << 20) + 123;

vector<int> g[N];
int dp[SIZE];

unsigned int bitcount(unsigned int x)
{
  x = ((x >> 1) & 0b01010101010101010101010101010101)
     + (x       & 0b01010101010101010101010101010101);
  x = ((x >> 2) & 0b00110011001100110011001100110011)
     + (x       & 0b00110011001100110011001100110011); 
  x = ((x >> 4) & 0b00001111000011110000111100001111)
     + (x       & 0b00001111000011110000111100001111); 
  x = ((x >> 8) & 0b00000000111111110000000011111111)
     + (x       & 0b00000000111111110000000011111111); 
  x = ((x >> 16)& 0b00000000000000001111111111111111)
     + (x       & 0b00000000000000001111111111111111); 
  return x;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int a;
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &a);
            g[i].push_back(a - 1);
        }
    }
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            int cur = g[i][j];
            for (int k = 0; k < (1 << m); k++) {
                if (dp[k] == 0) {
                    continue;
                }
                if (k & (1 << cur)) {
                    continue;
                }
                if (bitcount(k) != i) {
                    continue;
                }
                int u = (k | (1 << cur));
                dp[u] += dp[k];
            }
        }
    }
    /*
    for (int i = 0; i < (1 << m); i++) {
        printf("%d ", dp[i]);
    }
    puts("");
    */
    int res = 0;
    for (int i = 0; i < (1 << m); i++) {
        if (bitcount(i) == n) {
            res += dp[i];
        }
    }
    print(res);
    return 0;
}
