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

typedef long long llint;

const int BITS = 10;
const int N = (1 << BITS);
const int SIZE = 1234567;

char tstr[SIZE];
llint dp[N];

int main() {
    freopen("input.txt", "r", stdin);    
    
    int n;
    input(n);
    for (int i = 0; i < n; i++) {
        scanf("%s", tstr);
        int t = 0;
        for (int j = 0; tstr[j]; j++) {
            t |= 1 << (tstr[j] - '0');
        }
        assert(t < N);
        dp[t]++;
    }

    llint res = 0;
    const int mask = N - 1;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if ((i | j) == mask) {
                if (i != j) {
                    res += 1LL * dp[i] * dp[j];
                } else {
                    res += 1LL * dp[i] * (dp[j] - 1) / 2;
                }
            }
        }
    }
    print(res);

    return 0;
}
