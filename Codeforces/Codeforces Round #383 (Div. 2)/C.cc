#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return 1LL * a * b / gcd(a, b);
}

class Solution {
public:
    Solution(int n_, vector<int> ns_): n(n_), ns(ns_) {
        // pass
    }

    int solve() {
        int ans = 1;
        visit = vector<bool>(n, false);
        for (int i = 0; i < n; i++) {
            if (visit[i]) {
                continue;
            }
            int g = dfs(i, i, 0);
            if (g == -1) {
                return -1;
            }
            if (g % 2 == 0) {
                g /= 2;
            }
            ans = lcm(ans, g);
        }
        return ans;
    }

private:
    int dfs(int st, int cur, int len) {
        if (st == cur && len) {
            return len;
        }
        if (visit[cur]) {
            return -1;
        }
        visit[cur] = 1;
        int next = ns[cur] - 1;
        return dfs(st, next, len + 1);
    }
private:
    int n;
    vector<int> ns;
    vector<bool> visit;
};

void test() {
    vector<int> v1 = {2, 3, 1, 4};
    vector<int> v2 = {4, 4, 4, 4};
    vector<int> v3 = {2, 1, 4, 3};
    
    assert(Solution(v1.size(), v1).solve() == 3);
    assert(Solution(v2.size(), v2).solve() == -1);
    assert(Solution(v3.size(), v3).solve() == 1);
    
    // print("done!");
}

int main() {
    test();
    
    int n;
    vector<int> ns;

    input(n);
    ns.resize(n);
    for (int i = 0; i < n; i++) {
        input(ns[i]);
    }

    Solution S(n, ns);
    print(S.solve());

    return 0;
}
