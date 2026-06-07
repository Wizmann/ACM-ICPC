#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    int maxv = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxv = max(maxv, a[i]);
    }

    vector<int> spf(maxv + 1);
    vector<int> primes;
    for (int i = 2; i <= maxv; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > spf[i] || 1LL * i * p > maxv) {
                break;
            }
            spf[i * p] = p;
        }
    }

    vector<int> dp(n, 1), pre(n, -1);
    vector<int> best_idx(maxv + 1, -1);

    int ans_idx = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int t = x;

        while (t > 1) {
            int p = spf[t];
            int prev_value = x / p;
            int j = best_idx[prev_value];

            if (j != -1 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                pre[i] = j;
            }

            while (t % p == 0) {
                t /= p;
            }
        }

        int old = best_idx[x];
        if (old == -1 || dp[i] > dp[old]) {
            best_idx[x] = i;
        }

        if (dp[i] > dp[ans_idx]) {
            ans_idx = i;
        }
    }

    vector<int> ans;
    for (int cur = ans_idx; cur != -1; cur = pre[cur]) {
        ans.push_back(a[cur]);
    }
    reverse(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (int i = 0; i < (int)ans.size(); i++) {
        if (i) {
            cout << ' ';
        }
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}

/*
^^^test^^^
8
6 2 4 12 3 9 18 36
---
4
3 9 18 36
$$$test$$$

^^^test^^^
5
1 1 2 4 8
---
4
1 2 4 8
$$$test$$$

^^^test^^^
6
10 5 15 45 90 180
---
5
5 15 45 90 180
$$$test$$$
*/
