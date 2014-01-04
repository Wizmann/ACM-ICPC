#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int BUFFER = 128;
const int SIZE = 5;

llint need[SIZE];
llint have[SIZE];
llint cost[SIZE];
llint money;

llint calc(llint num) {
    llint res = 0;
    for (int i = 0; i < 3; i++) {
        llint t = max(0LL, num * need[i] - have[i]);
        res += t * cost[i];
    }
    return res;
}

llint solve()
{
    llint step = 10000000000000LL;
    llint now = 0;
    while (step) {
        llint half = step >> 1;
        llint mid = now + half;

        if (calc(mid) > money) {
            step = half;
        } else {
            now = mid + 1;
            step = step - half - 1;
        }
    }
    return now;
}

int main()
{
    freopen("input.txt", "r", stdin);
    char buffer[BUFFER];

    while (input(buffer)) {
        memset(need, 0, sizeof(need));
        memset(have, 0, sizeof(have));
        memset(cost, 0, sizeof(money));

        for (int i = 0; buffer[i]; i++) {
            switch (buffer[i]) {
                case 'B': need[0]++; break;
                case 'S': need[1]++; break;
                case 'C': need[2]++; break;
                default: break;
            }
        }

        for (int i = 0; i < 3; i++) {
            input(have[i]);
        }
        for (int i = 0; i < 3; i++) {
            input(cost[i]);
        }

        input(money);

        llint ans = solve() - 1;
        print(max(0LL, ans));
    }
    return 0;
}

