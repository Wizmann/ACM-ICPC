#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

#define print(x) cout << x << endl
#define input(x) cin >> x

using namespace std;

using llint = long long;

const int MAXI = 111111;

llint tris[MAXI];


llint tripow(llint x) {
    return x * x * x;
}

void init() {
    for (int i = 0; i < MAXI; i++) {
        tris[i] = tripow(i);
    }
}

llint get_idx(llint x) {
    return distance(tris, upper_bound(tris, tris + MAXI, x)) - 1;
}

void dfs(llint m, llint a, llint& c, llint& r) {
    if (m <= 0 || a <= 0) {
        c = r = 0;
        return;
    }

    m = min(m, tripow(a + 1) - 1);
    
    llint b = min(a, get_idx(m));
    
    llint c1, c2, r1, r2;
    dfs(m - tripow(b), b, c1, r1);
    dfs(tripow(b) - tripow(b - 1) - 1, b - 1, c2, r2);
    
    c1++;
    c2++;
    r1 += tripow(b);
    r2 += tripow(b - 1);
    
    if (c1 != c2) {
        if (c1 > c2) {
            c = c1; r = r1;
        } else {
            c = c2; r = r2;
        }
    } else {
        if (r1 > r2) {
            c = c1; r = r1;
        } else {
            c = c2; r = r2;
        }
    }
}

void solve(llint m, llint& c, llint& r) {
    dfs(m, get_idx(m), c, r);
}


int main() {
    init();
    llint m;
    input(m);
    llint c, r;
    solve(m, c, r);
    print(c << ' ' << r);
    return 0;
}
