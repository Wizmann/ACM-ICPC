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

const int ALPHA = 32;

int solution(string &S) {
    vector<int> minip(ALPHA, -1);
    vector<int> mini(ALPHA, INF);

    const int n = S.size();

    vector<int> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int c = S[i - 1] - 'a';

        dp[i] = dp[i - 1] + 1;
        if (minip[c] != -1) {
            assert(S[minip[c] - 1] - 'a' == c);
            dp[i] = min(dp[i], dp[minip[c] - 1]);
        }

        if (dp[i - 1] < mini[c]) {
            mini[c] = dp[i - 1];
            minip[c] = i;
        }
    }
    return dp[n];
}

int test(const string& s) {
    string s_ = s;
    return solution(s_);
}

int main() {
    assert(test("abccac") == 1);
    assert(test("abcdabcdabcd") == 2);
    assert(test("axaabyab") == 0);
    assert(test("aaa") == 0);
    assert(test("a") == 1);
    assert(test("zzza") == 1);
    assert(test("zzzaaa") == 0);
    assert(test("zzzbaaa") == 1);
    assert(test("ababac") == 1);
    assert(test("zzzaxyaa") == 0);
    assert(test("zxxxxxzxzx") == 0);

    puts("OK");

    return 0;
}

