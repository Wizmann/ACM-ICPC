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

const int DNA_MAX = 4;
const char DNA[] = "ATGC";
const int SIZE = 3333;

int dna1[SIZE];
int dna2[SIZE];
int n;
int A, B;

int delta[DNA_MAX + 1][DNA_MAX + 1];
llint dp[2][SIZE][3];

void convert(const string& s, int dna[]) {
    int length = s.size();
    for (int i = 1; i <= length; i++) {
        int v = -1;
        switch (s[i - 1]) {
            case 'A': v = 1; break;
            case 'T': v = 2; break;
            case 'G': v = 3; break;
            case 'C': v = 4; break;
            default: assert(false);
        }
        dna[i] = v;
    }
}

int main() {
    string s1, s2;
    input(s1);
    input(s2);

    convert(s1, dna1);
    convert(s2, dna2);

    memset(delta, -INF, sizeof(delta));

    for (int i = 1; i <= DNA_MAX; i++) {
        for (int j = 1; j <= DNA_MAX; j++) {
            scanf("%d", &delta[i][j]);
        }
    }

    scanf("%d%d", &A, &B);

    memset(dp, -INF, sizeof(dp));
    dp[0][0][0] = 0;

    assert(dna1[0] == 0);
    assert(dna2[0] == 0);
    
    int n = s1.size();
    int m = s2.size();
    int p = 0;

    dp[0][1][1] = -A;
    for (int i = 2; i <= m; i++) {
        dp[0][i][1] = dp[0][i - 1][1] - B;
    }

    for (int i = 1; i <= n; i++) {
        int q = p ^ 1;
        memset(dp[q], -INF, sizeof(dp[q]));

        for (int j = 0; j <= m; j++) {
            for (int k = 0; k < 3; k++) {
                int b1 = (k & 1) ? 1 : 0;
                int b2 = (k & 2) ? 1 : 0;

                if (b1 == 0 && b2 == 0) {
                    llint d = delta[dna1[i]][dna2[j]];

                    dp[q][j][k] = max(dp[q][j][k], dp[p][j - 1][0] + d);
                    dp[q][j][k] = max(dp[q][j][k], dp[p][j - 1][1] + d);
                    dp[q][j][k] = max(dp[q][j][k], dp[p][j - 1][2] + d);
                } else if (b1 == 1 && b2 == 0 && j - 1 >= 0) {
                    assert(k == 1);
                    dp[q][j][k] = max(dp[q][j][k], dp[q][j - 1][0] - A);
                    dp[q][j][k] = max(dp[q][j][k], dp[q][j - 1][1] - B);
                    dp[q][j][k] = max(dp[q][j][k], dp[q][j - 1][2] - A);
                } else if (b1 == 0 && b2 == 1) {
                    assert(k == 2);
                    dp[q][j][k] = max(dp[q][j][k], dp[p][j][0] - A);
                    dp[q][j][k] = max(dp[q][j][k], dp[p][j][1] - A);
                    dp[q][j][k] = max(dp[q][j][k], dp[p][j][2] - B);
                }
                // print(i, j, k, dp[q][j][k]);
            }
        }

        p = q;
    }

    llint maxi = -INFLL;
    for (int i = 0; i < 3; i++) {
        maxi = max(maxi, dp[p][m][i]);
    }
    print(maxi);

    return 0;
}

/*

^^^TEST^^^
T
T
5 -4 -4 -4 
-4 5 -4 -4 
-4 -4 5 -4 
-4 -4 -4 5 
123456 123456
-----
5
$$$TEST$$$

^^^TEST^^^
AT
AT
5 -4 -4 -4 
-4 5 -4 -4 
-4 -4 5 -4 
-4 -4 -4 5 
123456 123456
-----
10
$$$TEST$$$

^^^TEST^^^
ACT
ATC
5 -4 -4 -4 
-4 5 -4 -4 
-4 -4 5 -4 
-4 -4 -4 5 
123456 123456
-----
-3
$$$TEST$$$

^^^TEST^^^
ACT
ATC
5 -4 -4 -4 
-4 5 -4 -4 
-4 -4 5 -4 
-4 -4 -4 5 
0 0
-----
10
$$$TEST$$$

^^^TEST^^^
G
C
5 -100 -100 -100 
-100 5 -100 -100 
-100 -100 5 -100 
-100 -100 -100 5 
2 1
-----
-4
$$$TEST$$$

^^^TEST^^^
TG
TC
5 -100 -100 -100 
-100 5 -100 -100 
-100 -100 5 -100 
-100 -100 -100 5 
2 1
-----
1
$$$TEST$$$

^^^TEST^^^
T
AG
5 -100 -100 -100 
-100 5 -100 -100 
-100 -100 5 -100 
-100 -100 -100 5 
1 1
-----
-3
$$$TEST$$$

^^^TEST^^^
TC
AG
5 -100 -100 -100 
-100 5 -100 -100 
-100 -100 5 -100 
-100 -100 -100 5 
1 1
-----
-4
$$$TEST$$$

^^^TEST^^^
ATGG
ATCC
5 -4 -4 -4 
-4 5 -4 -4 
-4 -4 5 -4 
-4 -4 -4 5 
2 1
-----
4
$$$TEST$$$

*/
