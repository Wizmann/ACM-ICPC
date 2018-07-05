#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <deque>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int INF = 0x3f3f3f3f;

int n;
vector<int> ns;

int main() {
    while (input(n) && n) {
        ns = vector<int>(n + 1, 0);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }
        ns[n] = -INF;

        llint ans = 0;
        deque<int> dq;

        for (int i = 0; i <= n; i++) {
            while (!dq.empty() && ns[i] <= ns[dq.back()]) {
                int u = ns[dq.back()];
                dq.pop_back();
                int l = dq.empty()? 0: dq.back() + 1;
                int r = i - 1;
                ans = max(ans, 1LL * (r - l + 1) * u);
            }
            dq.push_back(i);
        }
        print(ans);
    }
    return 0;
}
