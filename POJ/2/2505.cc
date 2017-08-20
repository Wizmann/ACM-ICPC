#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

int main() {
    freopen("input.txt", "r", stdin);
    double n;
    while (input(n)) {
        while (n > 18) {
            n /= 18;
        }
        if (n <= 9) {
            puts("Stan wins.");
        } else {
            puts("Ollie wins.");
        }
    }
    return 0;
}

