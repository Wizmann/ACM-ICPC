#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int main() {
    int n, x;
    input(n);
    vector<int> st;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (st.empty() || x > *st.rbegin()) {
            st.push_back(x);
        }
        auto iter = upper_bound(st.begin(), st.end(), x);
        *iter = x;
    }
    print(st.size());
    return 0;
}
