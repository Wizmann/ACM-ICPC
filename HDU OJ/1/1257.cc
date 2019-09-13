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
const int MAXI = 33333;

int main() {
    int n;
    while (input(n)) {
        vector<int> ns(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        multiset<int> st;
        for (auto num : ns) {
            auto iter = st.lower_bound(num);
            if (iter != st.end()) {
                st.erase(iter);
            }
            st.insert(num);
        }
        print(st.size());
    }

    return 0;
}

