#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int INF = 0x3f3f3f3f;

int n;
vector<pair<int, int> > g;
vector<int> values;
set<int> succ;

int dfs(int cur, int mini, int maxi) {
    if (cur == -1) {
        return 0;
    }
    
    int right = g[cur].second;
    int left = g[cur].first;
    
    if (values[cur] < mini) {
        return dfs(right, mini, maxi);
    }
    
    if (values[cur] > maxi) {
        return dfs(left, mini, maxi);
    }

    succ.insert(values[cur]);
    int res = 1;
    res += dfs(left, mini, values[cur]);
    res += dfs(right, values[cur], maxi);

    return res;
}

int main() {
    input(n);

    g.resize(n + 1);
    values.resize(n + 1);

    set<int> st;
    for (int i = 1; i <= n; i++) {
        st.insert(i);
    }

    int a, b, c;
    for (int i = 1; i <= n; i++) {
        input(a >> b >> c);
        if (b != -1) {
            st.erase(st.find(b));
        }
        if (c != -1) {
            st.erase(st.find(c));
        }
        values[i] = a;
        g[i] = {b, c};
    }

    assert(st.size() == 1);

    int root = *st.begin();
    dfs(root, -INF, INF);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += succ.count(values[i]);
    }
    print(n - ans);
    return 0;
}
