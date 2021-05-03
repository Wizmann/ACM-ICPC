#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

const int SIZE = 123456;

int n;
vector<int> A;
vector<int> B;
vector<int> dp;
char buffer[SIZE];

llint solve() {
    llint res = 0;
    for (int i = 0; i < n; i++) {
        res += A[i] ^ B[i];
    }

    dp.resize(n);
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = (i + 1 < n? dp[i + 1]: 0) + (A[i] ^ B[i]);
    }

    int pre1 = 0;
    int pre2 = 0;
    for (int i = 0; i < n - 1; i++) {
        llint diff = (A[i] ^ 0) + (B[i] ^ 1);
        res = min(res, diff + pre1 + pre2 + 1 + dp[i + 1]);
        pre1 += A[i] ^ 1;
        pre2 += B[i];
    }
    return res;
}

int main() {
    int T;
    input(T);

    while (T--) {
        scanf("%d", &n);

        A.clear();
        B.clear();

        scanf("%s", buffer);
        for (int i = 0; i < n; i++) {
            A.push_back(buffer[i] - '0');
        }

        scanf("%s", buffer);
        for (int i = 0; i < n; i++) {
            B.push_back(buffer[i] - '0');
        }

        for (int i = 0; i < 3; i++) {
            A.push_back(0);
            B.push_back(0);
        }
        n += 3;

        printf("%lld\n", solve());
    }
    return 0;
}

/*

^^^TEST^^^
3
5
11111
00000
5
10100
01010
5
00000
00001
-----
2
3
1
$$$TEST$$$

^^^TEST^^^
1
100
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110
0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001
---
1
$$$TEST$$$

^^^TEST^^^
1
10
1100101000
0000101000
---
2
$$$TEST$$$

^^^TEST^^^
1
10
0001110000
1010110000
---
3
$$$TEST$$$

^^^TEST^^^
1
10
1100101000
0000101000
---
2
$$$TEST$$$

^^^TEST^^^
1
10
1011101000
0111001000
---
2
$$$TEST$$$

^^^TEST^^^
1
10
1111011000
0000111100
---
2
$$$TEST$$$

^^^TEST^^^
1
20
11010101000000000000
01001011111110010000
---
11
$$$TEST$$$


^^^TEST^^^
1
20
11111000000000000000
10001000011110001000
---
8
$$$TEST$$$

*/
