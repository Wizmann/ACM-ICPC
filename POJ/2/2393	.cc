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

const int SIZE = 11111;
const int INF = 0x3f3f3f3f;

int Cs[SIZE];
int Ys[SIZE];

int main() {
    int n, s;
    input(n >> s);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &Cs[i], &Ys[i]);
    }

    int pre = INF;
    llint ans = 0;
    for (int i = 0; i < n; i++) {
        int cur = min(pre + s, Cs[i]);
        ans += 1LL * Ys[i] * cur;
        pre = cur;
    }
    print(ans);

    return 0;
}
