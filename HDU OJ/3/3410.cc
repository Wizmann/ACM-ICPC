#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int INF = 0x3f3f3f3f;

int n;
vector<int> ns;

void solve(int l, int r, int delta, vector<int>& ans) {
    vector<int> st;
    for (int i = l; i != r; i += delta) {
        int maxi = 0;
        int maxp = -1;

        while (!st.empty() && ns[st.back()] < ns[i]) {
            if (maxi < ns[st.back()]) {
                maxi = ns[st.back()];
                maxp = st.back();
            }
            st.pop_back();
        }

        ans[i] = maxp + 1;
        st.push_back(i);
    }
}

int main() {
    int T;
    input(T);

    int case_ = 0;

    while (T--) {
        input(n);
        ns.resize(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        vector<int> ansl(n, 0);
        vector<int> ansr(n, 0);
        solve(0, n, +1, ansl);
        solve(n - 1, -1, -1, ansr);

        printf("Case %d:\n", ++case_);

        for (int i = 0; i < n; i++) {
            printf("%d %d\n", ansl[i], ansr[i]);
        }
    }

    return 0;
}
