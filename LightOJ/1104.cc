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

int main() {
    int T;
    input(T);
    int case_ = 0;
    while (T--) {
        int n;
        scanf("%d", &n);

        double p = 1.0;

        int cnt = n;

        while (p > 0.5) {
            p = p * (cnt - 1) / n;
            cnt--;
        };

        printf("Case %d: %d\n", ++case_, n - cnt);
    }
    return 0;
}
