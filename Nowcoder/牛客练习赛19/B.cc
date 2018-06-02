#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
 
using namespace std;
 
#define print(x) cout << x << endl
#define input(x) cin >> x
 
const int SIZE = 10;
 
int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}
 
int lcm(int a, int b) {
    return 1LL * a * b / gcd(a, b);
}
 
pair<int, int> add(pair<int, int> pa, pair<int, int> pb) {
    if (pa.first == 0) {
        return pb;
    }
    if (pb.first == 0) {
        return pa;
    }
    int b = lcm(pa.second, pb.second);
    int a = 1LL * pa.first * b / pa.second
        + 1LL * pb.first * b / pb.second;
    int g = gcd(a, b);
    return {a / g, b / g};
}
 
int bit_count(int x) {
    int cnt = 0;
    while (x) {
        cnt += x & 1;
        x >>= 1;
    }
    return cnt;
}
 
 
class Solution {
public:
    Solution(int n_, int k_) : n(n_), k(k_) {
        dp.resize(1 << k);
 
 
        dp[0] = {1, 1};
        for (int i = 1; i < (1 << k); i++) {
            dp[i] = {0, 1};
        }
    }
 
    string solve() {
        queue<int> q;
        vector<bool> visited(1 << k, false);
        q.push(0);
 
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (visited[cur]) {
                continue;
            } else {
                visited[cur] = true;
            }
 
            for (int i = 0; i < k; i++) {
                int pos = i;
                while (pos < k && (cur & (1 << pos))) {
                    pos++;
                }
 
                if (pos < k) {
                    int next = cur | (1 << pos);
                    pair<int, int> v = dp[cur];
                    v.second *= k;
                    dp[next] = add(dp[next], v);
                    if (bit_count(next) < n) {
                        q.push(next);
                    }
                }
            }
        }
 
        pair<int, int> res = {0, 1};
        for (int i = 0; i < (1 << k); i++) {
            if (bit_count(i) == n) {
                res = add(res, dp[i]);
            }
        }
 
        int a = res.second - res.first;
        int b = res.second;
 
        if (a == 0) {
            return "0/1";
        } else {
            int g = gcd(a, b);
            return to_string(a/g) + "/" + to_string(b / g);
        }
    }
private:
    int n, k;
    vector<pair<int, int> > dp;
};
 
int main() {
    int T;
    input(T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);
 
        print(Solution(n, k).solve());
    }
    return 0;
}