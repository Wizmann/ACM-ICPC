#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 123456;

int64_t value[SIZE];
int64_t n, m;

int64_t calc(int64_t limit)
{
    int64_t l = 1, r = m;
    int64_t step = r;
    while (step) {
        int64_t half = step >> 1;
        int64_t mid = l + half;

        int64_t edges = 0;
        if (mid % 2 == 1) {
            edges = mid * (mid - 1) / 2;
        } else {
            edges = mid * (mid - 1) / 2 + (mid / 2 - 1);
        }

        if (edges > limit) {
            step = half;
        } else {
            l = mid + 1;
            step = step - half - 1;
        }
    }
    return l - 1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int64_t a, b;
    input(n >> m);
    int64_t x = calc(n - 1);

    for (int i = 0 ; i < m; i++) {
        input(a >> b);
        value[i] = b;
    }

    sort(value, value + m, greater<int>());

    int64_t ans = 0;
    for (int64_t i = 0; i < x; i++) {
        ans += value[i];
    }

    print(ans);

    return 0;
}

