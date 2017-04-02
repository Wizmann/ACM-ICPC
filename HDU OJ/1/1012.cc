#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int main() {
    int n = 1;
    double ans = 1;
    puts("n e");
    puts("- -----------");
    puts("0 1");
    for (int i = 1; i < 10; i++) {
        ans += 1.0 / n;
        if (i <= 2) {
            printf("%d %g\n", i, ans);
        } else {
            printf("%d %.9lf\n", i, ans);
        }
        n = n * (i + 1);
    }
    return 0;
}
