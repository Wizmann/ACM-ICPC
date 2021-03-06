/*$$$
[Description]
A team of k (1 <= K <= 100) workers should paint a fence which contains N (1 <= N <= 16 000) planks numbered from 1 to N from left to right. 

Each worker i (1 <= i <= K) should sit in front of the plank Si and he may paint only a compact consecutive interval [Li, Ri] (inclusive), and Li <= Si <= Ri.

Also a worker should not paint more than Li planks and for each painted plank he will receive Pi (1 <= Pi <= 10 000).

* A plank should be painted by no more than one worker.
* A plank could be left with blank.
* A worker can paint no planks.
* All the numbers Si should be distinct. 

Write a program that determines the total maximal income obtained by the K workers. 

[Tags]
dp

[Difficulty]
4.5

[Url]
http://poj.org/problem?id=1821
$$$*/

// Result: 18740430	wizmann	1821	Accepted	1044K	110MS	G++	2128B	2018-07-04 01:23:42
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int N = 22222;

struct Worker {
    Worker(int l_, int p_, int s_): \
            l(l_), p(p_), s(s_) {
        // pass
    }

    int l, p, s;

    bool operator < (const Worker& other) const {
        return s < other.s;
    }
};

int n, k;
llint dp[2][N];
vector<Worker> workers;

int main() {
    freopen("d.txt", "r", stdin);
    // int case_ = 1;
    while (input(k >> n)) {
        // print("===" << case_++ << "===");
        // print(k << ' ' << n);
        memset(dp, 0, sizeof(dp));

        workers.clear();
        workers.push_back(Worker(-1, -1, -1));
        int l, p, s, r;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &l, &p, &s);
            // printf("%d %d %d\n", l, p, s);
            workers.push_back(Worker(l, p, s));
        }
        sort(workers.begin(), workers.end());

        llint ans = 0;
        p = 0;
        for (int i = 1; i <= n; i++) {
            llint maxi = 0;
            int q = p ^ 1;
            memset(dp[q], 0, sizeof(dp[q]));

            s = workers[i].s;

            r = min(k, s + workers[i].l - 1);
            l = s;
            for (int j = 0; j < workers[i].l && l > 0 && r - l + 1 <= workers[i].l; j++) {
                maxi = max(maxi, dp[p][l - 1] + workers[i].p * (s - l + 1));
                l--;
            }
            while (r >= s) {
                llint u = maxi + workers[i].p * (r - s);
                dp[q][r] = max(dp[q][r], u);
                if (l > 0) {
                    maxi = max(maxi, dp[p][l - 1] + workers[i].p * (s - l + 1));
                    l--;
                }
                r--;
            }
            for (int j = 0; j <= k; j++) {
                dp[q][j] = max(dp[q][j], dp[p][j]);
                // printf("%lld\t", dp[q][i] < 0? -1: dp[q][i]);
                ans = max(ans, dp[q][j]);
            }
            // puts("");
            p = q;
        }
        print(ans);
    }
    return 0;
}

