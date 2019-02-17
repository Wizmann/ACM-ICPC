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
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        bool flag = (a / (b - 1)) % 2;
        if (flag) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
