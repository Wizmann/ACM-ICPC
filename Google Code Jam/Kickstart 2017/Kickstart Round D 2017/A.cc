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

const int SIZE = 2222;
const llint INF = 0x3f3f3f3f3f3f3f3fLL;

llint dp[SIZE][SIZE];

struct City {
    int s, f, d;
};

llint get_bus_time(llint cur, const City& city) {
    llint a = cur - city.s;
    llint b = city.f;

    if (a <= 0) {
        return city.s;
    } else if (a % b == 0) {
        return city.s + (a / b) * city.f;
    } else {
        return city.s + (a / b + 1) * city.f;
    }
}

class Solution {
public:
    void solve() {
        memset(dp, INF & (0xff), sizeof(dp));

        input(n >> ts >> tf);

        int a, b, c;
        for (int i = 0; i < n - 1; i++) {
            input(a >> b >> c);
            cities.push_back({a, b, c});
        }

        do_solve();
    }
private:
    void do_solve() {
        dp[0][0] = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == INF) {
                    continue;
                }
                
                // print(i << ' ' << j << ' ' << dp[i][j]);

                const auto& city = cities[i];

                llint cur = dp[i][j];
                llint arr1 = get_bus_time(cur + ts, city) + city.d;
                llint arr2 = get_bus_time(cur, city) + city.d;

                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], arr1);
                dp[i + 1][j] = min(dp[i + 1][j], arr2);
                
            }
        }

        llint ans = -1;
        for (int i = 0; i <= n; i++) {
            // print(n - 1 << ' ' << i << ' ' << dp[n - 1][i]);
            if (dp[n - 1][i] <= tf) {
                ans = max(ans, 1LL * i);
            }
        }

        if (ans == -1) {
            puts("IMPOSSIBLE");
        } else {
            print(ans);
        }
    }
private:
    int n, ts, tf;
    vector<City> cities;
};

int main() {
    // freopen("input.txt", "r", stdin);
    
    int T;
    input(T);

    for (int case_ = 0; case_ < T; case_++) {
        printf("Case #%d: ", case_ + 1);

        auto S = Solution();
        S.solve();
    }

    return 0;
}

