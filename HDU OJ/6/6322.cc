#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

int main() {
    int T;
    input(T);

    int x;
    while (T--) {
        scanf("%d", &x);

        if (x == 1) {
            puts("5");
        } else if (x == 2) {
            puts("7");
        } else {
            printf("%lld\n", 5LL + x);
        }
    }
    return 0;
}
