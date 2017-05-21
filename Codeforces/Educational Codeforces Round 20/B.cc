#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int INF = 0x3f3f3f3f;

int main() {
    int n;
    vector<int> ns;

    input(n);
    ns.resize(n);
    set<int> st;
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);

        if (ns[i] == 0) {
            st.insert(i);
        }
    }

    for (int i = 0; i < n; i++) {
        auto iter = st.upper_bound(i);
        int res = INF;
        if (iter != st.end()) {
            res = min(res, *iter - i);
        }
        if (iter != st.begin()) {
            --iter;
            res = min(res, i - *iter);
        }
        printf("%d ", res);
    }
    puts("");
    return 0;
}
