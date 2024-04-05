#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

const int SIZE = 12345678;
int a[SIZE];

int main() {
    int n;
    int A, B, C;
    scanf("%d%d%d%d%d", &n, &A, &B, &C, a);
    for (int i = 1; i < n; i++)
        a[i] = ((long long) a[i - 1] * A + B) % 100000001;
    for (int i = 0; i < n; i++)
        a[i] = a[i] % C + 1;

    double res = 0;

    for (int i = 0; i < n; i++) {
        res += 1.0 * min(a[i], a[(i + 1) % n]) / (1LL * a[i] * a[(i + 1) % n]);
    }

    printf("%.3f\n", res);

    return 0;
}

/*
^^^TEST^^^
3 2 0 4 1
---
1.167
$$$TEST$$$
*/
