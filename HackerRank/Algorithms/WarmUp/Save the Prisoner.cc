#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

int main() {
    int T;
    llint n, m, s;
    input(T);
    while (T--) {
        input(n >> m >> s);
        print((m + s - 2) % n + 1);
    }
    return 0;
}
