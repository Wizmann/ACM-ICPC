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

int n, m;
vector<int> ps;
vector<int> ns;

int count(int l, int r) {
    if (l > m) {
        return 0;
    }
    r = min(r, m + 1);
    l = max(1, l);
    return ps[r - 1] - ps[l - 1];
}

llint solve1(int cur) {
    llint res = 0;
    
    for (int i = 1; cur * i <= m; i++) {
        res += 1LL * i * count(cur * i, cur * (i + 1));
    }

    return res;
}

llint solve2(int cur, llint& acc) {
    llint res = ns[cur] + acc;
    acc += ns[cur];
    return res;
}

int main() {
    input(n >> m);
    ns = vector<int>(m + 1, 0);
    ps = vector<int>(m + 1);
    
    int cur = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &cur);
        ps[cur]++;
    }
    
    for (int i = 1; i <= m; i++) {
        ps[i] += ps[i - 1];
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; 1LL * i * j <= m; j++) {
            ns[i * j] += 1LL * j * count(i, i + 1);
            if (1LL * i * (j + 1) <= m) {
                ns[i * (j + 1)] -= 1LL * j * count(i, i + 1);
            }
        }
    }
    
    llint res = 0;
    llint acc = 0;
    for (int i = 1; i <= m; i++) {
        llint t = 0;
        t += solve1(i);
        t += solve2(i, acc);
        // print(t);
        res ^= t;
    }
    print(res);
    return 0;
}

