#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1111111;
const int INF = 0x3f3f3f3f;

vector<int> dp(SIZE, INF);

void init() {
    dp[0] = 0;
    for (int i = 1; i < SIZE; i++) {
        dp[i] = min(dp[i], dp[i - 1] + 1);
        for (int j = 2; j <= i && 1LL * i * j < SIZE; j++) {
            int k = i * j;
            dp[k] = min(dp[k], dp[max(i, j)] + 1);
        }
    }
}


int main() {
    init();
    
    int n, q;
    input(n);
    
    while (n--) {
        input(q);
        print(dp[q]);
    }
    
    return 0;
}
