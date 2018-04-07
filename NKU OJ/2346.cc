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

int n, k;
vector<int> ns;

int main() {
    input(n >> k);
    ns.resize(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }

    sort(ns.begin(), ns.end());

    int kk = k;
    llint res = 0;
    for (int i = 0; i < n; i++) {
        if (kk > ns[i]) {
            res += kk;
            kk -= 10;
        } else {
            res += ns[i];
        }
    }
    print(res);
    return 0;
}
