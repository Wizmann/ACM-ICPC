#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x 

long long solve(int x) {
    int t = 0;
    if (x & 1) {
        t = x / 2;
    } else {
        t = x / 2 - 1;
        if (t & 1) {
            t = x / 2 - 2;
        }
    }
    return static_cast<long long>(t) * t / (x - 2 * t);
}

int main() {
    int T, x;
    input(T);
    while (T--) {
        input(x);
        print(solve(x));
    }
    return 0;
}
