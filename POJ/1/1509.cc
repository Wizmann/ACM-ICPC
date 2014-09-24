// Result: wizmann	1509	Accepted	272K	16MS	C++	1247B	2014-09-17 00:44:22
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 12345;

char instr[SIZE];

int solve(const char* str, int n)
{
    if (n <= 1) {
        return 0;
    }

    int p = 0, q = 1;
    while (p < n && q < n) {
        if (str[p] < str[q]) {
            q++;
        } else if (str[p] > str[q]) {
            p = q;
            q++;
        } else {
            int i, l = p, r = q;
            for (i = 0; i < n; i++) {
                int ll = l % n, rr = r % n;
                if (str[ll] < str[rr]) {
                    q = r;
                    break;
                } else if (str[ll] > str[rr]) {
                    p = q;
                    q = rr;
                    break;
                }
                l++; r++;
            }
            if (i == n) {
                break;
            }
        }
    }
    return p;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    input(T);
    while (T--) {
        scanf("%s", instr);
        int u = solve(instr, strlen(instr));
        printf("%d\n", ++u);
    }
    return 0;
}
