#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int N = 55;
const int D = 10100;

char dp[N * D];
int n, d;
int A[N];

void do_package()
{
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = N * D - 1; j >= 0; j--) {
            if (dp[j] && j + A[i] < N * D) {
                dp[j + A[i]] = 1;
            }
        }
    }
}

void solve(int &val, int &day)
{
    val = day = 0;
    while (1) {
        bool flag = false;
        for (int i = val + d; i > val; i--) {
            if (dp[i]) {
                val = i;
                day++;
                flag = true;
                break;
            }
        }
        if (!flag) break;
    }
}


int main()
{
    freopen("input.txt", "r", stdin);
    while (input(n >> d)) {
        for (int i = 0; i < n; i++) {
            input(A[i]);
        }
        do_package();
        
        int a, b;
        solve(a, b);
        print(a << ' ' << b);
    }
    return 0;
}

