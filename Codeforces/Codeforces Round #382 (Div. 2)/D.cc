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

bool is_prime(int x) {
    for (llint i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int solve(int x) {
    if (is_prime(x)) {
        return 1;
    }
    if (x % 2 == 0) {
        return 2;
    }
    if (is_prime(x - 2)) {
        return 2;
    }
    return 3;
}

int main() {
    int x;
    input(x);
    if (x <= 3) {
        puts("1");
    } else {
        print(solve(x));
    }
    return 0;
}
