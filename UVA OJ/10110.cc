#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cmath>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

bool solve(llint n) {
    llint m = sqrt(n);
    return m * m == n;
}

int main() {
    llint n;
    
    assert(solve(3) == false);
    assert(solve(6241) == true);
    assert(solve(8191) == false);

    while (input(n) && n) {
        if (solve(n)) {
            puts("yes");
        } else {
            puts("no");
        }
    }

    return 0;
}
