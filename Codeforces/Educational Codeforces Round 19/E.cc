#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

vector<int> dp;
vector<int> ns;
int n, q;

inline int readint() {
    char c=getchar(); int f=1,ret=0;
    while (c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while (c<='9'&&c>='0') {ret=ret*10+c-'0';c=getchar();}
    return ret * f;
}

class Solution {
public:
    void solve(const vector<pair<int, int> >& qv, int k, vector<int>& ans) {
        if (k < 1000) {
            fill(dp.begin(), dp.end(), -1);
        }

        for (auto p: qv) {
            int q = p.first;
            int idx = p.second;
            if (k < 1000) {
                ans[idx] = dfs1(q, k);
            } else {
                ans[idx] = dfs2(q, k);
            }
        }
    }
private:
    int dfs1(int q, int k) {
        if (q >= n) {
            return 0;
        }
        if (dp[q] != -1) {
            return dp[q];
        }
        return dp[q] = dfs1(q + ns[q] + k, k) + 1;
    }
    
    int dfs2(int q, int k) {
        if (q >= n) {
            return 0;
        }
        return dfs2(q + ns[q] + k, k) + 1;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    map<int, vector<pair<int, int> > > queries;

    input(n);
    ns.resize(n);
    for (int i = 0; i < n; i++) {
        ns[i] = readint();
    }

    input(q);
    int a, b;
    for (int i = 0; i < q; i++) {
        a = readint();
        b = readint();
        a--;
        if (queries.count(b) == 0) {
            queries[b] = vector<pair<int, int> >();
        }

        queries[b].push_back({a, i});
    }

    dp = vector<int>(n, -1);
    vector<int> ans(q, 0);
    for (auto& p: queries) {
        int k = p.first;
        auto& qv = p.second;
        sort(qv.begin(), qv.end());
        Solution().solve(qv, k, ans);
    }

    for (auto item: ans) {
        printf("%d\n", item);
    }

    return 0;
}
