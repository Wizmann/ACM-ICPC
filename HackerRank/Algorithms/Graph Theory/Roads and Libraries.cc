#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 123456;

int n, m, c1, c2;

int father[SIZE];

int find_father(int x) {
    if (father[x] == x) {
        return x;
    }
    return father[x] = find_father(father[x]);
}

void init() {
    for (int i = 0; i < SIZE; i++) {
        father[i] = i;
    }
}

int main() {
    int T;
    int a, b;
    input(T);
    while (T--) {
        input(n >> m >> c1 >> c2);

        init();

        for (int i = 0; i < m; i++) {
            input(a >> b);

            father[find_father(b)] = find_father(a);
        }

        map<int, int> mp;
        for (int i = 1; i <= n; i++) {
            mp[find_father(i)]++;
        }

        llint ans = 0;
        for (const auto& p: mp) {
            ans += min(1LL * c1 + (p.second - 1) * c2, 1LL * c1 * p.second);
        }
        print(ans);
    }
    return 0;
}
