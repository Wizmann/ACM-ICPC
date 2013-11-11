//Result: Wizmann   UVA 340 Accepted    0 KB    19 ms   C++ 4.5.3   1250 B  2013-11-01 14:30:20 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1024;

int A[SIZE], B[SIZE];
int n;
char strong[SIZE];
int cnt[10];

void judge(int& a, int& b)
{
    a = b = 0;
    memset(strong, 0, sizeof(strong));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        if (A[i] == B[i]) {
            strong[i] = 1;
            a++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!strong[i]) {
            cnt[A[i]]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!strong[i]) {
            if (cnt[B[i]]) {
                b++;
                cnt[B[i]]--;
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int a, b;
    int cas = 1;
    while (input(n) && n) {
        printf("Game %d:\n", cas++);
        for (int i = 0; i < n; i++) {
            input(A[i]);
        }

        while (1) {
            for (int i = 0; i < n; i++) {
                input(B[i]);
            }
            if (!B[0]) break;

            judge(a, b);
            printf("    (%d,%d)\n", a, b);
        }
    }
    return 0;
}

