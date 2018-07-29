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

const int MOD = 1000000000 + 7;

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    while (input(n) && n) {
        vector<int> A(n), B(n);
        multiset<int> st;
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
            A[i] -= i + 1;
            st.insert(A[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &B[i]);
            B[i]--;
        }

        sort(B.begin(), B.end());
        int cur = 0;
        llint ans = 0;
        for (int i = 0; i < n; i++) {
            int b = B[i];
            while (cur < b) {
                multiset<int>::iterator iter = st.find(A[cur]);
                st.erase(iter);
                cur++;
            }
            ans = (ans + *st.rbegin()) % MOD;
            // print(*st.rbegin());
            st.insert(*st.rbegin() - n - i - 1);
        }
        print(ans);
    }
    return 0;
}
