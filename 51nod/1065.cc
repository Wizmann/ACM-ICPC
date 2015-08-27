#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <climits>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

int main() {
    int n, x;
    input(n);
    
    set<llint> st;
    llint prefix_sum = 0;
    llint ans = numeric_limits<int>::max();
    st.insert(0);
    for (int i = 0; i < n; i++) {
        input(x);
        prefix_sum += x;

        auto iter = st.lower_bound(prefix_sum);
        if (iter != st.begin()) {
            llint u = *(--iter);
            ans = min(ans, prefix_sum - u);
        }
        st.insert(prefix_sum);
    }
    print(ans);
    return 0;
}
