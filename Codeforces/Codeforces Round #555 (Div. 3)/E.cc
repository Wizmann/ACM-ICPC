#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int n;
vector<int> ns;
multiset<int> st;

int main() {
    input(n);
    ns = vector<int>(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
        ns[i] %= n;
    }

    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        st.insert(x % n);
    }

    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        int u = n - ns[i];
        auto iter = st.lower_bound(u);

        if (iter == st.end()) {
            iter = st.begin();
        }

        // print(*iter);

        res[i] = (*iter + ns[i]) % n;
        st.erase(iter);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    puts("");

    return 0;
}
