// Result: wizmann  3617    Accepted    708K    16MS    G++ 912B    2014-06-30 14:39:03
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 2048;

int n;
char cows[SIZE];

bool do_cmp(int l, int r)
{
    while (l < r) {
        if (cows[l] == cows[r]) {
            l++; r--;
        } else {
            return cows[l] < cows[r];
        }
    }
    return true;
}

int main()
{
    char tmp[10];
    input(n);
    for (int i = 0; i < n; i++) {
        scanf("%s", tmp);
        cows[i] = *tmp;
    }
    int l = 0, r = n - 1;
    for (int i = 0; i < n; i += 80) {
        for (int j = 0; j < 80 && l <= r; j++) {
            if (do_cmp(l, r)) {
                putchar(cows[l++]);
            } else {
                putchar(cows[r--]);
            }
        }
        puts("");
    }
    return 0;
}

