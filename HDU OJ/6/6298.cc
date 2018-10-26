#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int xyz[][3] = {
    {2, 3, 6},
    {2, 4, 4},
    {3, 3, 3},
};


int main() {
    int T;
    input(T);

    while (T--) {
        int n;
        scanf("%d", &n);

        llint res = -1;

        for (int i = 0; i < 3; i++) {
            int x = xyz[i][0];
            int y = xyz[i][1];
            int z = xyz[i][2];

            if (n % x != 0 || n % y != 0 || n % z != 0) {
                continue;
            }

            res = max(res, 1LL * (n / x) * (n / y) * (n / z));
        }

        print(res);
    }
    return 0;
}

