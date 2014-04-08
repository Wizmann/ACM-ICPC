// Result: 6125860   Mar 23, 2014 6:26:54 PM    Wizmann  C - Unusual Product     GNU C++0x  Accepted    405 ms  0 KB
#include <cstdio>
#include <iostream>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1024;


int main()
{
    int n, q, u, ans = 0, a, b;
    input(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &u);
            if (i == j) ans += u;
        }
    }

    ans &= 1;
    input(q);
    while (q--) {
        scanf("%d", &a);
        if (a == 3) printf("%d", ans);
        else {
            scanf("%d", &b);
            ans ^= 1;
        }
    }
    return 0;
}

