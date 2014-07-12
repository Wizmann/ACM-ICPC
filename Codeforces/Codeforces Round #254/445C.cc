#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 512;
int n, m;

int vv[SIZE];

int main()
{
    int a, b, c;
    input(n >> m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", vv + i);
    }

    double ans = 0;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        ans = max(ans, double(vv[a] + vv[b]) / c);
    }
    printf("%.10lf\n", ans);
    return 0;
}

