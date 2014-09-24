// Result: wizmann	2593	Accepted	8456K	266MS	C++	1070B	2014-09-10 23:28:46
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int INF = 0x3f3f3f3f;

const int SIZE = 1000100;

int ltor[SIZE], rtol[SIZE];
int n, array[SIZE];

void calc(int* dp, int from, int to, int delta)
{
    int sum = -INF, t = 0;
    for (int i = from; i != to; i += delta) {
        t += array[i];
        sum = max(sum, t);
        dp[i] = sum;
        t = max(t, 0);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    while (input(n) && n) {
        int ans = -INF;
        for (int i = 0; i < n; i++) {
            scanf("%d", array + i);
        }
        memset(ltor, 0, sizeof(ltor));
        memset(rtol, 0, sizeof(rtol));

        calc(ltor, 0, n, 1);
        calc(rtol, n - 1, -1,  -1);

        for (int i = 0; i + 1 < n; i++) {
            int l = ltor[i];
            int r = rtol[i + 1];
            ans = max(ans, l + r);
        }
        print(ans);
    }
    return 0;
}


