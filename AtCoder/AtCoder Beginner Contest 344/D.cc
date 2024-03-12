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

llint fastpow(llint a, llint b, llint MOD) {
    llint res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
            res %= MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

const llint ALPHA = 31;
const llint MOD = 23456789;
string S;
vector<llint> mypow;
vector<llint> prefixHash;
int n;
int m;

llint gethash(const string& s) {
    llint h = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        h = (h * ALPHA) % MOD;
        h += s[i] - 'a' + 1;
    }
    return (h % MOD + MOD) % MOD;
}

int main() {
    input(S);
    n = S.size();

    mypow = vector<llint>(n + 1, 0);
    mypow[0] = 1;

    for (int i = 1; i <= n; i++) {
        mypow[i] = (mypow[i - 1] * ALPHA) % MOD;
    }

    prefixHash = vector<llint>(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        prefixHash[i] = (prefixHash[i - 1] * ALPHA % MOD + S[i - 1] - 'a' + 1) % MOD;
        prefixHash[i] = (prefixHash[i] % MOD + MOD) % MOD;
    }

    input(m);

    vector<int> dp[2];
    dp[0] = vector<int>(n + 1, INF);
    dp[1] = vector<int>(n + 1, INF);
    dp[0][0] = 0;

    int ptr = 0;
    for (int i = 0; i < m; i++) {
        int q;
        input(q);

        int qtr = ptr ^ 1;
        dp[qtr] = dp[ptr];

        for (int j = 0; j < q; j++) {
            string s;
            input(s);

            llint h = gethash(s);

            for (int k = n; k >= 0; k--) {
                if (dp[ptr][k] < INF && int(k + s.size()) <= n) {
                    llint nxt = prefixHash[k + s.size()] - (prefixHash[k] * mypow[s.size()]) % MOD;
                    nxt = (nxt % MOD + MOD) % MOD;
                    if (h == nxt) {
                        // print(s, S.substr(k, s.size()));
                        assert(s == S.substr(k, s.size()));
                        dp[qtr][k + s.size()] = min(dp[qtr][k + s.size()], dp[ptr][k] + 1);
                    } else {
                        assert(s != S.substr(k, s.size()));
                    }
                }
            }
        }

        ptr = qtr;
    }

    /*
    for (int i = 0; i <= n; i++) {
        printf("%d ", dp[i]);
    }
    puts("");
    */

    if (dp[ptr][n] >= INF) {
        print(-1);
    } else {
        print(dp[ptr][n]);
    }


    return 0;
}

/*

^^^TEST^^^
abcde
3
3 ab abc abcd
4 f c cd bcde
2 e de
-----
2
$$$TEST$$$


^^^TEST^^^
abcde
3
2 ab abc
3 f c bcde
1 e
-----
-1
$$$TEST$$$

^^^TEST^^^
aaabbbbcccc
6
2 aa aaa
2 dd ddd
2 ab aabb
4 bbaa bbbc bbb bbcc
2 cc bcc
3 ccc cccc ccccc
-----
4
$$$TEST$$$

^^^TEST^^^
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
6
2 aa aaa
2 a aaa
2 a aaaaaaaaaaa
4 aaaaaa a a a 
2 a aaaa
3 aa aaa aaaaa
-----
-1
$$$TEST$$$

*/
