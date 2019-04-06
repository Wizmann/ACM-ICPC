#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 123456;

int n;
vector<pair<double, int> > banks;
double dp[SIZE];

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    input(T);
    int case_ = 0;
    double tp;
    while (T--) {
        input(tp >> n);
        banks.clear();

        int m;
        double p;
        for (int i = 0; i < n; i++) {
            scanf("%d%lf", &m, &p);
            banks.push_back({p, m});
        }
        sort(banks.begin(), banks.end());
        fill(dp, dp + SIZE, 100);
        dp[0] = 0.0;

        for (int i = 0; i < n; i++) {
            int money = banks[i].second;
            p = banks[i].first;

            for (int j = SIZE - 1; j >= 0; j--) {
                if (dp[j] <= 1) {
                    assert(j + money < SIZE);
                    double pp = 1 - (1 - dp[j]) * (1 - p);
                    if (pp >= tp) {
                        continue;
                    }
                    dp[j + money] = min(dp[j + money], pp);
                }
            }
        }

        printf("Case %d: ", ++case_);
        for (int i = SIZE - 1; i >= 0; i--) {
            if (i == 0 || (dp[i] >= 0 && dp[i] <= tp)) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
