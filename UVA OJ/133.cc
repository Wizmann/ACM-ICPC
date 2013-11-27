//Result: 133   The Dole Queue  Accepted    C++ 0.012   2013-11-22 07:37:55
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const size_t SIZE = 24;

int n, k, m;
int A[SIZE];
int sz;

void init()
{
    for (int i = 0; i<n; i++) {
        A[i] = i;
    }
    sz = n;
}

void next_availA(int &a)
{
    while (A[a] == -1) {
        a++;
        a %= n;
    }
}

void next_availB(int &b)
{
    while (A[b] == -1) {
        b--;
        b = (b + n) % n;
    }
}

void do_select(int &a, int &b)
{
    next_availA(a);
    next_availB(b);

    for (int i = 0; i < k; i++) {
        a = (a + 1) % n;
        next_availA(a);
    }

    for (int i = 0; i < m; i++) {
        b = (b - 1 + n) % n;
        next_availB(b);
    }
    A[a] = A[b] = -1;
}

string show(int x)
{
    char buffer[16];
    if (x < 10) {
        sprintf(buffer, "  %d", x);
    } else if (x < 100) {
        sprintf(buffer, " %d", x);
    } else sprintf(buffer, "%d", x);
    return string(buffer);
}

int main()
{
    freopen("input.txt", "r", stdin);
    int a, b;
    while (input(n >> k >> m) && n + k + m) {
        init();
        k--; m--;
        a = 0; b = n - 1;
        while (sz) {
            do_select(a, b);
            if (a != b) {
                printf("%s%s", show(a + 1).c_str(), show(b + 1).c_str());
                sz -= 2;
            } else {
                printf("%s", show(a + 1).c_str());
                sz -= 1;
            }
            if (sz) printf(",");
        }
        puts("");
    }
    return 0;
}
