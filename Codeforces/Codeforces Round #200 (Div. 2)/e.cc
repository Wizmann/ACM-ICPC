//Result: 4505075	 Sep 19, 2013 8:52:15 PM	Wizmann	 E - Read Time	 GNU C++	Accepted	436 ms	1572 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

typedef long long llint;

const int SIZE = 100100;
const llint MAXI = 10000000000LL;

int n, m;
llint H[SIZE], P[SIZE];

bool solve(llint T) {
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (abs(H[i] - P[cur]) > T) {
            continue;
        }
        
        if (P[cur] == H[i]) cur++;
        llint maxi = 0;
        
        if (P[cur] > H[i]) maxi = H[i] + T;
        else maxi = max(
            H[i] + T - 2LL * (H[i] - P[cur]),
            H[i] + (T - (H[i] - P[cur])) / 2);

        while (maxi >= P[cur] && cur < m) cur++;
    }
    return cur == m;
}

int main()
{
    freopen("input.txt", "r", stdin);
    input(n >> m);
    for (int i = 0; i < n; i++) {
        input(H[i]);
    }

    for (int i = 0; i < m; i++) {
        input(P[i]);
    }

    llint l = 0;
    llint step = MAXI * 64;

    while (step) {
        llint half = step >> 1;
        llint mid = l + half;

        if (!solve(mid)) {
            l = mid + 1;
            step = step - half - 1;
        } else {
            step = half;
        }
    }
    print(l);
    return 0;
}
