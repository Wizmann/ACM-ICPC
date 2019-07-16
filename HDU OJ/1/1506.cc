#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int INF = 0x3f3f3f3f;

vector<int> ns;

int main() {
    int n;
    while (input(n) && n) {
        ns.resize(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }
        ns.push_back(-INF);

        llint res = 0;
        vector<int> st;

        for (int i = 0; i <= n; i++) {
            int cur = ns[i];
            while (!st.empty() && ns[st.back()] > cur) {
                int pre = st.back();
                st.pop_back();
                int l = st.empty()? 0: st.back() + 1;
                int r = i - 1;
                res = max(res, 1LL * (r - l + 1) * ns[pre]);
            }
            st.push_back(i);
        }

        print(res);
    }
    return 0;
}

