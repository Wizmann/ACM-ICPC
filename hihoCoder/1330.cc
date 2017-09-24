#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

int n;
vector<int> ns;

int dfs(int p, int init, int step) {
    if (step > 0 && p == init) {
        return step;
    }

    return dfs(ns[p], init, step + 1);
}

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return 1LL * a * b / gcd(a, b);
}

int main() {
    input(n);
    ns.resize(n);

    int res = 1;

    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
        ns[i]--;
    }

    for (int i = 0; i < n; i++) {
        res = lcm(res, dfs(i, i, 0));
    }

    print(res);

    return 0;
}
