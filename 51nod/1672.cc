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
#define loop(i, n) for (int i = 0; i < n; i++)

typedef long long llint;

int n, k, m;
multiset<int> st;
vector<llint> ns;
vector<pair<int, int> > ps;

int main() {
    freopen("input.txt", "r", stdin);
    input(n >> k >> m);
    
    ns = vector<llint>(n, 0);
    loop(i, n) {
        scanf("%lld", &ns[i]);
        if (i - 1 >= 0) {
            ns[i] += ns[i - 1];
        }
    }
    
    int a, b;
    loop(i, m) {
        scanf("%d%d", &a, &b);
        ps.push_back({--a, --b});
    }
    sort(ps.begin(), ps.end());
    
    llint ans = 0;
    loop(i, m) {
        st.insert(ps[i].second);
        while (!st.empty() && *st.begin() < ps[i].first) {
            st.erase(st.begin());
        }
        while (st.size() > k) {
            st.erase(st.begin());
        }
        if (st.size() != k) {
            continue;
        }
        int r = *st.begin();
        int l = ps[i].first;
        ans = max(ans, ns[r] - (l - 1 >= 0? ns[l - 1]: 0));
    }
    print(ans);
    return 0;
}
