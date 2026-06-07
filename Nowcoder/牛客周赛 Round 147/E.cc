#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int calc(const string& s, const string& a, const string& b) {
    int x = a.size();
    int y = b.size();
    int m = x + y;

    vector<int> dp(m + 1, INF);
    dp[0] = 0;

    auto relax_insert = [&]() {
        for (int i = 0; i < x; i++) {
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        }
        for (int i = x; i < m; i++) {
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        }
    };

    relax_insert();

    for (char c : s) {
        vector<int> ndp(m + 1, INF);

        // Before a: this character may be unrelated, or may start a.
        ndp[0] = min(ndp[0], dp[0]);
        if (c == a[0]) {
            ndp[1] = min(ndp[1], dp[0]);
        }

        // Inside a: characters must be consecutive, so only the next needed
        // character can be consumed here.
        for (int i = 1; i < x; i++) {
            if (c == a[i]) {
                ndp[i + 1] = min(ndp[i + 1], dp[i]);
            }
        }

        // Between a and b.
        ndp[x] = min(ndp[x], dp[x]);
        if (c == b[0]) {
            ndp[x + 1] = min(ndp[x + 1], dp[x]);
        }

        // Inside b.
        for (int i = 1; i < y; i++) {
            if (c == b[i]) {
                ndp[x + i + 1] = min(ndp[x + i + 1], dp[x + i]);
            }
        }

        // After both words.
        ndp[m] = min(ndp[m], dp[m]);

        dp.swap(ndp);
        relax_insert();
    }

    return dp[m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    cout << min(calc(s, "greet", "invite"), calc(s, "invite", "greet")) << '\n';

    return 0;
}

/*
^^^TEST^^^
1
a
---
11
$$$TEST$$$

^^^TEST^^^
15
greetxyzinvite
---
0
$$$TEST$$$

^^^TEST^^^
15
invitexxxgreet
---
0
$$$TEST$$$

^^^TEST^^^
17
gxxxrxxxexxxexxxt
---
9
$$$TEST$$$
*/
