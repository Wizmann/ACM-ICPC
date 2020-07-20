#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int INF = 0x3f3f3f3f;

char buffer[8888];

vector<int> kmp_next(const char* s, int n) {
    vector<int> res(n + 1, -1);

    for (int pre = -1, suf = 0; pre < n && suf < n; /* pass */) {
        if (pre == -1 || s[pre] == s[suf]) {
            suf++;
            pre++;
            res[suf] = pre;
        } else {
            pre = res[pre];
        }
    }
    return res;
}

int intlen(int x) {
    if (x == 0) {
        assert(false);
    }
    int len = 0;
    while (x) {
        len++;
        x /= 10;
    }
    return len;
}

int solve(const string& s) {
    int n = s.size();
    vector<int> dp(n + 1, INF);

    dp[0] = 0;
    dp[n] = n + 1;

    for (int i = 0; i < n; i++) {
        int m = n - i;
        vector<int> next = kmp_next(s.data() + i, m);
        dp[i] = min(dp[i], i + 1);
        for (int j = 1; j <= m; j++) {
            assert(next[j] >= 0);
            if (j % (j - next[j]) == 0) {
                dp[i + j] = min(dp[i + j], dp[i] + j + 1);
                int loop = j - next[j];
                dp[i + j] = min(dp[i + j], dp[i] + intlen(j / loop) + loop);
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        printf("%d ", dp[i]);
    }
    puts("");

    return dp[n];
}

void test() {
    assert(solve("xxxcac") == 6);
    assert(solve("ababcaababcbac") == 14);
    assert(solve("aaaabbccdabababa") == 12);
    assert(solve("bbbacacb") == 7);
    assert(solve("abaabacccccccc") == 6);
    assert(solve("abaaba") == 4);
    assert(solve("a") == 2);
    assert(solve("abccd") == 6);
    assert(solve("abcc") == 5);
    assert(solve("abbcc") == 6);
    assert(solve("abcab") == 6);
    assert(solve("aaaaaaaaaa") == 3);
    assert(solve("cczabababab") == 7);
}

int main() {
    test();

    scanf("%s", buffer);
    print(solve(string(buffer)));
    return 0;
}
