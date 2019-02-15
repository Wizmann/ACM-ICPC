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

typedef long long llint;

const llint INF = 1e12;

llint solve(llint a, llint b) {
    if (a < 0 || a > b || b > INF) {
        return INF;
    }

    // print(a << ' ' << b);

    if (a == 0) {
        return b;
    }

    llint ans = INF;
    do
    {
        // (c, d)(a, b)
        llint d = a - 1;
        llint c = 2LL * d - b;
        if (c + 1 < 0) {
            return INF;
        }
        if (c != a) {
            ans = min(ans, solve(c, b));
        }
        if (c + 1 != a) {
            ans = min(ans, solve(c + 1, b));
        }
    } while(0);

    do
    {
        // (a, b)(c, d)
        llint c = b;
        llint d = 2LL * b - a;

        if (d <= INF && d != b) {
            ans = min(ans, solve(a, d));
        }
        if (d + 1 <= INF && d + 1 != b) {
            ans = min(ans, solve(a, d + 1));
        }
    } while(0);

    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        llint ans = solve(a, b);
        if (ans >= INF) {
            ans = -1;
        }
        print(ans);
    }
    return 0;
}
