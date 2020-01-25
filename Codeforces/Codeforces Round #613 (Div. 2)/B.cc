#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
 
using namespace std;
 
#define input(x) cin >> x
#define print(x) cout << x << endl
 
typedef long long llint;
 
const llint INF = 0x3f3f3f3f3f3f3f3fLL;
 
int main() {
    int T;
    input(T);
    while (T--) {
        int n;
        input(n);
        vector<int> ns(n);
 
        multiset<llint> st;
        st.insert(0);
 
        llint tot = 0;
        llint maxi = -INF;
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
            tot += ns[i];
 
            if (i == n - 1) {
                st.erase(st.find(0));
            }
 
            maxi = max(maxi, tot - *st.begin());
            st.insert(tot);
        }
 
        if (tot > maxi) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
