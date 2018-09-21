#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 18;

struct Status {
    Status() {
        // pass
    }

    Status(int leader_, int candidates_) {
        leader = leader_;
        candidates = candidates_;
    }

    int leader;
    int candidates;

    int to_hash() {
        return (leader << SIZE) + candidates;
    }

    static Status from_hash(int hash) {
        Status s;
        s.candidates = hash & ((1 << SIZE) - 1);
        s.leader = hash >> SIZE;
        return s;
    }
};

int n;
double pmat[SIZE][SIZE];
double dp[SIZE << SIZE];

double solve(int leader, int candidates) {
    if (leader == 0 && candidates == 0) {
        return 1.0;
    }

    int h = Status(leader, candidates).to_hash();
    if (dp[h] >= 0) {
        return dp[h];
    }

    double res = 0;
    for (int i = 0; i < n; i++) {
        if (!(candidates & (1 << i))) {
            continue;
        }
        double p = pmat[leader][i];
        double cur = 0;

        int next = candidates ^ (1 << i);

        cur += p * solve(leader, next);
        cur += (1 - p) * solve(i, next);

        res = max(res, cur);
    }
    return dp[h] = res;
}

int main() {
    freopen("input.txt", "r", stdin);

    input(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &pmat[i][j]);
        }
    }

    memset(dp, -1, sizeof(dp));
    
    double ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, solve(i, ((1 << n) - 1) ^ (1 << i)));
    }
    print(ans);

    return 0;
}
