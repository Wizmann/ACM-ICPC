#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int INF = 0x3f3f3f3f;

int solve(const vector<int>& ns, int s, int l) {
    int n = ns.size() - 1;
    multiset<int> st;
    int p = 1;
    vector<int> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        st.insert(ns[i]);
        while (!st.empty()) {
            int mini = *st.begin();
            int maxi = *st.rbegin();

            if (maxi - mini > s || dp[p - 1] == INF) {
                st.erase(st.find(ns[p]));
                p++;
            } else {
                break;
            }
        }
        assert(1 <= p <= n);

        if (i - p + 1 >= l) {
            dp[i] = min(dp[i], dp[p - 1] + 1);
        }
    }

    /*
    for (int i = 1; i <= n; i++) {
        printf("%d ", dp[i]);
    }
    print("");
    */

    return dp[n] == INF? -1: dp[n];
}

int main() {
    int n, s, l;
    input(n >> s >> l);
    vector<int> ns(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ns[i]);
    }
    print(solve(ns, s, l));

    return 0;
}
